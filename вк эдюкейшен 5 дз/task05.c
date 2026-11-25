/*
 * Задача 5. Balance factor
 * Для каждого узла заполнить balance_factor = высота левого поддерева
 * минус высота правого. Высота пустого дерева 0, листа 1.
 */
#include <stdio.h>
#include "functions.h"

static int check_factors(const TreeNode *root, const int *expected,
                         size_t *index)
{
    int failed;

    if (root == NULL) return 0;
    failed = check_factors(root->left, expected, index);
    printf("  узел %d: balance_factor = %d (ожидалось %d)\n",
           root->data, root->balance_factor, expected[*index]);
    if (root->balance_factor != expected[*index]) failed = 1;
    (*index)++;
    return check_factors(root->right, expected, index) || failed;
}

static int run_test(const int *arr, size_t n, const int *expected, int height)
{
    TreeNode *root;
    size_t index = 0;
    int result, failed;

    if (build_tree(arr, n, &root) != 0) return 1;
    print_tree(root);
    result = fill_balance_factors(root);
    failed = check_factors(root, expected, &index) || result != height;
    printf("  высота %d (ожидалось %d)\n", result, height);
    free_tree(&root);
    return failed;
}

int main(void)
{
    int balanced[] = {4, 2, 6, 1, 3, 5, 7};
    int zero[] = {0, 0, 0, 0, 0, 0, 0};
    int left[] = {5, 3, NO_NODE, 2, NO_NODE, NO_NODE, NO_NODE, 1};
    int left_factors[] = {0, 1, 2, 3};
    int right[] = {1, NO_NODE, 2, NO_NODE, NO_NODE, NO_NODE, 3};
    int right_factors[] = {-2, -1, 0};

    if (run_test(balanced, 7, zero, 3)) return 1;
    if (run_test(left, 8, left_factors, 4)) return 1;
    if (run_test(right, 7, right_factors, 3)) return 1;
    if (run_test(balanced, 1, zero, 1)) return 1;
    if (run_test(NULL, 0, NULL, 0)) return 1;
    return 0;
}
