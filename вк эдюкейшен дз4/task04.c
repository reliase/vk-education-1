/*
 * Задача 4. Поиск произведения максимального и минимального элементов
 *
 * Дано бинарное дерево поиска (BST), представленное в виде массива.
 * Необходимо найти произведение минимального и максимального значений.
 */

#include <stdio.h>
#include "functions.h"

static int run_test(const int *arr, int n, long long expected)
{
    TreeNode *root;
    long long res;

    if (build_tree(arr, n, &root) != 0) {
        printf("ошибка: нет памяти\n");
        return -1;
    }
    print_tree(root);
    free_tree(&root);

    if (bst_min_max_product(arr, n, &res)) {
        printf("  min * max = %lld (ожидалось %lld)\n", res, expected);
    } else {
        printf("  дерево пустое\n");
    }
    return 0;
}

int main(void)
{
    int t1[] = {8, 3, 10, 1, 6, NO_NODE, 14};
    int t2[] = {5, 3, NO_NODE, 2, NO_NODE, NO_NODE, NO_NODE, 1};
    int t3[] = {7};
    int t4[] = {0, -5, 9, -10, NO_NODE, NO_NODE, 100000};

    if (run_test(t1, 7, 14) != 0) return 1;
    if (run_test(t2, 8, 5) != 0) return 1;
    if (run_test(t3, 1, 49) != 0) return 1;
    if (run_test(t4, 7, -1000000) != 0) return 1;
    if (run_test(t3, 0, 0) != 0) return 1;
    return 0;
}
