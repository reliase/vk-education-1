/*
 * Задача 6. Преобразование в зеркальное дерево
 * Поменять местами левое и правое поддеревья каждого узла.
 * Обоснование корректности и сложности — в functions.c.
 */
#include <stdio.h>
#include "functions.h"

static int same_tree(const TreeNode *a, const TreeNode *b)
{
    if (a == NULL || b == NULL) return a == b;
    return a->data == b->data && a->balance_factor == b->balance_factor
        && same_tree(a->left, b->left) && same_tree(a->right, b->right);
}

static int run_test(const int *arr, const int *expected, size_t n)
{
    TreeNode *root, *other;
    int failed;

    if (build_tree(arr, n, &root) != 0) return 1;
    if (build_tree(expected, n, &other) != 0) {
        free_tree(&root);
        return 1;
    }
    fill_balance_factors(root);
    fill_balance_factors(other);
    printf("До: "); print_tree(root);
    mirror_tree(root);
    printf("После: "); print_tree(root);
    failed = !same_tree(root, other);
    free_tree(&other);
    if (build_tree(arr, n, &other) != 0) {
        free_tree(&root);
        return 1;
    }
    fill_balance_factors(other);
    mirror_tree(root);
    if (!same_tree(root, other)) failed = 1;
    printf("  отражение и двойное отражение: %s\n",
           failed ? "ошибка" : "верно");
    free_tree(&root);
    free_tree(&other);
    return failed;
}

int main(void)
{
    int a[] = {8, 3, 10, 1, 6, NO_NODE, 14};
    int mirror[] = {8, 10, 3, 14, NO_NODE, 6, 1};
    int left[] = {2, 1, NO_NODE};
    int right[] = {2, NO_NODE, 1};

    if (run_test(a, mirror, 7)) return 1;
    if (run_test(left, right, 3)) return 1;
    if (run_test(a, a, 1)) return 1;
    if (run_test(NULL, NULL, 0)) return 1;
    return 0;
}
