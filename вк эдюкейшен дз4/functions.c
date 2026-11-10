#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* Задача 1 */

static TreeNode *node_new(int data)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static int build_rec(const int *arr, int n, int i, TreeNode **out)
{
    TreeNode *node;

    *out = NULL;
    if (i >= n || arr[i] == NO_NODE) {
        return 0;
    }
    node = node_new(arr[i]);
    if (node == NULL) {
        return -1;
    }
    *out = node;
    if (build_rec(arr, n, 2 * i + 1, &node->left) != 0) {
        return -1;
    }
    if (build_rec(arr, n, 2 * i + 2, &node->right) != 0) {
        return -1;
    }
    return 0;
}

int build_tree(const int *arr, int n, TreeNode **root)
{
    if (build_rec(arr, n, 0, root) != 0) {
        free_tree(root);
        return -1;
    }
    return 0;
}

void free_tree(TreeNode **root)
{
    if (*root == NULL) {
        return;
    }
    free_tree(&(*root)->left);
    free_tree(&(*root)->right);
    free(*root);
    *root = NULL;
}

static void print_rec(const TreeNode *node)
{
    if (node == NULL) {
        printf("-");
        return;
    }
    printf("%d", node->data);
    if (node->left != NULL || node->right != NULL) {
        printf("(");
        print_rec(node->left);
        printf(", ");
        print_rec(node->right);
        printf(")");
    }
}

void print_tree(const TreeNode *root)
{
    print_rec(root);
    printf("\n");
}

/* Задача 2 */

static int is_mirror(const TreeNode *a, const TreeNode *b)
{
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    return a->data == b->data
        && is_mirror(a->left, b->right)
        && is_mirror(a->right, b->left);
}

int is_symmetric(const TreeNode *root)
{
    if (root == NULL) {
        return 1;
    }
    return is_mirror(root->left, root->right);
}

/* Задача 3 */

static int tree_size(const TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + tree_size(root->left) + tree_size(root->right);
}

int min_depth(const TreeNode *root)
{
    const TreeNode **queue;
    const TreeNode *node;
    int head = 0, tail = 0, level_end, depth = 0;

    if (root == NULL) {
        return 0;
    }
    queue = malloc((size_t)tree_size(root) * sizeof(const TreeNode *));
    if (queue == NULL) {
        return -1;
    }
    queue[tail++] = root;

    while (head < tail) {
        depth++;
        level_end = tail;
        while (head < level_end) {
            node = queue[head++];
            if (node->left == NULL && node->right == NULL) {
                free(queue);
                return depth;
            }
            if (node->left != NULL) {
                queue[tail++] = node->left;
            }
            if (node->right != NULL) {
                queue[tail++] = node->right;
            }
        }
    }
    free(queue);
    return depth;
}

/* Задача 4 */

int bst_min_max_product(const int *arr, int n, long long *res)
{
    int min_i = 0, max_i = 0;

    if (n <= 0 || arr[0] == NO_NODE) {
        return 0;
    }
    while (2 * min_i + 1 < n && arr[2 * min_i + 1] != NO_NODE) {
        min_i = 2 * min_i + 1;
    }
    while (2 * max_i + 2 < n && arr[2 * max_i + 2] != NO_NODE) {
        max_i = 2 * max_i + 2;
    }
    *res = (long long)arr[min_i] * arr[max_i];
    return 1;
}

/* Задача 5 */

int is_same_tree(const TreeNode *a, const TreeNode *b)
{
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    return a->data == b->data
        && is_same_tree(a->left, b->left)
        && is_same_tree(a->right, b->right);
}
