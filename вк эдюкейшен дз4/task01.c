/*
 * Задача 1. Восстановление бинарного дерева из массива
 *
 * Дан массив, представляющий бинарное дерево (например, в виде уровнями —
 * level-order).
 * Необходимо восстановить структуру бинарного дерева.
 */

#include <stdio.h>
#include "functions.h"

static int run_test(const int *arr, int n)
{
    TreeNode *root;
    int i;

    printf("[");
    for (i = 0; i < n; i++) {
        if (arr[i] == NO_NODE) {
            printf("%snull", i > 0 ? ", " : "");
        } else {
            printf("%s%d", i > 0 ? ", " : "", arr[i]);
        }
    }
    printf("] -> ");

    if (build_tree(arr, n, &root) != 0) {
        printf("ошибка: нет памяти\n");
        return -1;
    }
    print_tree(root);
    free_tree(&root);
    return 0;
}

int main(void)
{
    int t1[] = {1, 2, 3, 4, 5, 6, 7};
    int t2[] = {10, 5, 15, NO_NODE, 7, 12};
    int t3[] = {1, 2, NO_NODE, 3};
    int t4[] = {42};

    if (run_test(t1, 7) != 0) return 1;
    if (run_test(t2, 6) != 0) return 1;
    if (run_test(t3, 4) != 0) return 1;
    if (run_test(t4, 1) != 0) return 1;
    if (run_test(t4, 0) != 0) return 1;
    return 0;
}
