#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "functions.h"

static int build_rec(const int *arr, size_t n, size_t i, TreeNode **out)
{
    TreeNode *node;

    *out = NULL;
    if (i >= n || arr[i] == NO_NODE) return 0;
    node = malloc(sizeof *node);
    if (node == NULL) return -1;
    node->data = arr[i];
    node->balance_factor = 0;
    node->left = NULL;
    node->right = NULL;
    *out = node;
    /* Проверяем индексы до умножения, чтобы избежать переполнения. */
    if (i < n / 2 && build_rec(arr, n, 2*i+1, &node->left) != 0)
        return -1;
    if (n > 1 && i < (n-1) / 2
        && build_rec(arr, n, 2*i+2, &node->right) != 0)
        return -1;
    return 0;
}

int build_tree(const int *arr, size_t n, TreeNode **root)
{
    if (root == NULL) return -1;
    *root = NULL;
    if (n > 0 && arr == NULL) return -1;
    if (build_rec(arr, n, 0, root) != 0) {
        free_tree(root);
        return -1;
    }
    return 0;
}

void free_tree(TreeNode **root)
{
    if (root == NULL || *root == NULL) return;
    free_tree(&(*root)->left);
    free_tree(&(*root)->right);
    free(*root);
    *root = NULL;
}

static void print_rec(const TreeNode *root)
{
    if (root == NULL) {
        printf("-");
        return;
    }
    printf("%d", root->data);
    if (root->left != NULL || root->right != NULL) {
        printf("(");
        print_rec(root->left);
        printf(", ");
        print_rec(root->right);
        printf(")");
    }
}

void print_tree(const TreeNode *root)
{
    print_rec(root);
    printf("\n");
}

/* Задача 1. Полное дерево: все уровни, кроме последнего, заполнены,
 * последний заполняется слева направо (complete binary tree).
 * BFS рассматривает места детей по порядку. После первого пустого места
 * любой непустой ребёнок означает нарушение полноты.
 * Динамическая очередь хранит узлы; время O(n), память O(n). */
static int queue_push(const TreeNode ***queue, size_t *cap, size_t *tail,
                      const TreeNode *node)
{
    const TreeNode **tmp;
    size_t new_cap;

    if (*tail == *cap) {
        if (*cap > SIZE_MAX / 2) return -1;
        new_cap = *cap == 0 ? 16 : *cap * 2;
        if (new_cap > SIZE_MAX / sizeof *tmp) return -1;
        tmp = realloc(*queue, new_cap * sizeof *tmp);
        if (tmp == NULL) return -1;
        *queue = tmp;
        *cap = new_cap;
    }
    (*queue)[(*tail)++] = node;
    return 0;
}

int is_complete(const TreeNode *root)
{
    const TreeNode **queue = NULL;
    const TreeNode *node, *children[2];
    size_t cap = 0, head = 0, tail = 0;
    int gap = 0, j, result = 1;

    if (root == NULL) return 1;
    if (queue_push(&queue, &cap, &tail, root) != 0) return -1;
    while (head < tail && result == 1) {
        node = queue[head++];
        children[0] = node->left;
        children[1] = node->right;
        for (j = 0; j < 2; j++) {
            if (children[j] == NULL) {
                gap = 1;
            } else if (gap) {
                result = 0;
                break;
            } else if (queue_push(&queue, &cap, &tail, children[j]) != 0) {
                result = -1;
                break;
            }
        }
    }
    free(queue);
    return result;
}

/* Задача 2. Мин-куча хранит первый невыданный элемент каждого массива.
 * Её корень — минимум среди всех оставшихся элементов. Заменяем его
 * следующим из того же массива, а если массив исчерпан — удаляем корень.
 * Для N элементов: O(K + N*log(K+1)) времени, O(K) рабочей памяти,
 * плюс O(N) для результата. Начальная куча строится за O(K). */
typedef struct {
    int value;
    size_t array;
    size_t index;
} HeapItem;

static void merge_sift(HeapItem *heap, size_t n, size_t i)
{
    size_t child;
    HeapItem tmp;

    while (i < n / 2) {
        child = 2*i + 1;
        if (child + 1 < n && heap[child+1].value < heap[child].value)
            child++;
        if (heap[i].value <= heap[child].value) break;
        tmp = heap[i]; heap[i] = heap[child]; heap[child] = tmp;
        i = child;
    }
}

int merge_k_arrays(const int *const *arrays, const size_t *sizes,
                   size_t k, int **out, size_t *out_n)
{
    size_t i, total = 0, active = 0, n = 0, pos = 0;
    HeapItem *heap, item;
    int *result;

    if (out == NULL || out_n == NULL) return -1;
    *out = NULL;
    *out_n = 0;
    if (k > 0 && (arrays == NULL || sizes == NULL)) return -1;
    for (i = 0; i < k; i++) {
        if (sizes[i] > 0 && arrays[i] == NULL) return -1;
        if (sizes[i] > SIZE_MAX - total) return -1;
        total += sizes[i];
        if (sizes[i] > 0) active++;
    }
    if (total == 0) return 0;
    if (total > SIZE_MAX / sizeof *result
        || active > SIZE_MAX / sizeof *heap) return -1;
    result = malloc(total * sizeof *result);
    heap = malloc(active * sizeof *heap);
    if (result == NULL || heap == NULL) {
        free(result); free(heap);
        return -1;
    }
    for (i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            heap[n].value = arrays[i][0];
            heap[n].array = i;
            heap[n++].index = 0;
        }
    }
    for (i = n / 2; i > 0; i--) merge_sift(heap, n, i-1);
    while (n > 0) {
        item = heap[0];
        result[pos++] = item.value;
        item.index++;
        if (item.index < sizes[item.array]) {
            item.value = arrays[item.array][item.index];
            heap[0] = item;
        } else {
            heap[0] = heap[--n];
        }
        merge_sift(heap, n, 0);
    }
    free(heap);
    *out = result;
    *out_n = total;
    return 0;
}

/* Задача 3. Для k-го минимума поддерживаем max-кучу из k наименьших:
 * новый элемент меньше корня вытесняет текущий максимум. Для k-го
 * максимума используем min-кучу. Корень в конце — искомый элемент.
 * Время O(n*log(k+1)), память O(k); исходный массив не меняется. */
static int above(int a, int b, int largest)
{
    return largest ? a < b : a > b;
}

static void value_sift(int *heap, size_t n, size_t i, int largest)
{
    size_t child;
    int tmp;

    while (i < n / 2) {
        child = 2*i + 1;
        if (child + 1 < n && above(heap[child+1], heap[child], largest))
            child++;
        if (!above(heap[child], heap[i], largest)) break;
        tmp = heap[i]; heap[i] = heap[child]; heap[child] = tmp;
        i = child;
    }
}

int kth_array(const int *arr, size_t n, size_t k, int largest, int *out)
{
    int *heap;
    size_t i;

    if (k == 0 || k > n) return 0;
    if (arr == NULL || out == NULL || k > SIZE_MAX / sizeof *heap) return -1;
    heap = malloc(k * sizeof *heap);
    if (heap == NULL) return -1;
    for (i = 0; i < k; i++) heap[i] = arr[i];
    for (i = k / 2; i > 0; i--) value_sift(heap, k, i-1, largest);
    for (i = k; i < n; i++) {
        if (above(heap[0], arr[i], largest)) {
            heap[0] = arr[i];
            value_sift(heap, k, 0, largest);
        }
    }
    *out = heap[0];
    free(heap);
    return 1;
}

/* Задача 4. LNR выдаёт BST по возрастанию, RNL — по убыванию.
 * Уменьшаем счётчик при посещении узла и останавливаемся на k-м.
 * Время O(h+k), в худшем случае O(n), стек O(h).
 * Предполагается корректное BST с уникальными ключами. */
static int kth_rec(const TreeNode *root, size_t *k, int largest, int *out)
{
    if (root == NULL) return 0;
    if (kth_rec(largest ? root->right : root->left, k, largest, out))
        return 1;
    (*k)--;
    if (*k == 0) {
        *out = root->data;
        return 1;
    }
    return kth_rec(largest ? root->left : root->right, k, largest, out);
}

int kth_bst(const TreeNode *root, size_t k, int largest, int *out)
{
    if (out == NULL) return -1;
    if (k == 0) return 0;
    return kth_rec(root, &k, largest, out);
}

/* Задача 5. Обратный обход: сначала получаем высоты детей, затем
 * заполняем поле узла и возвращаем его высоту. Высота каждого поддерева
 * вычисляется один раз: время O(n), стек O(h). */
int fill_balance_factors(TreeNode *root)
{
    int left, right;

    if (root == NULL) return 0;
    left = fill_balance_factors(root->left);
    right = fill_balance_factors(root->right);
    root->balance_factor = left - right;
    return 1 + (left > right ? left : right);
}

/* Задача 6. Меняем местами детей и зеркалим оба поддерева.
 * Лист и пустое дерево уже зеркальны. Если оба поддерева отражены,
 * обмен их мест завершает отражение всего дерева (индукция по высоте).
 * Время O(n), стек O(h). После отражения BST обычно перестаёт быть BST.
 * Знак уже заполненного balance_factor также меняется. */
void mirror_tree(TreeNode *root)
{
    TreeNode *tmp;

    if (root == NULL) return;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    root->balance_factor = -root->balance_factor;
    mirror_tree(root->left);
    mirror_tree(root->right);
}
