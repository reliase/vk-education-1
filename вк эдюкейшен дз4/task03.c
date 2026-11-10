/*
 * Задача 3. Поиск минимальной глубины бинарного дерева
 *
 * Дано бинарное дерево.
 * Необходимо найти его минимальную глубину (расстояние от корня до
 * ближайшего листа).
 */

#include <stdio.h>
#include "functions.h"

static int run_test(const int *arr, int n, int expected)
{
    TreeNode *root;

    if (build_tree(arr, n, &root) != 0) {
        printf("ошибка: нет памяти\n");
        return -1;
    }
    print_tree(root);
    printf("  минимальная глубина: %d (ожидалось %d)\n",
           min_depth(root), expected);
    free_tree(&root);
    return 0;
}

int main(void)
{
    int t1[] = {3, 9, 20, NO_NODE, NO_NODE, 15, 7};
    int t2[] = {1, 2, NO_NODE, 3, NO_NODE, NO_NODE, NO_NODE, 4};
    int t3[] = {1, 2, 3, 4, 5, 6, 7};
    int t4[] = {1, 2, 3, 4, NO_NODE, NO_NODE, 5, 6};

    if (run_test(t1, 7, 2) != 0) return 1;
    if (run_test(t2, 8, 4) != 0) return 1;
    if (run_test(t3, 7, 3) != 0) return 1;
    if (run_test(t4, 8, 3) != 0) return 1;
    if (run_test(t1, 1, 1) != 0) return 1;
    if (run_test(t1, 0, 0) != 0) return 1;
    return 0;
}
