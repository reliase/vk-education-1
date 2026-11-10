/*
 * Задача 2. Симметричное бинарное дерево
 *
 * Дано бинарное дерево.
 * Необходимо определить, является ли оно симметричным относительно своей
 * середины.
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
    printf("  симметричное: %s (ожидалось %s)\n",
           is_symmetric(root) ? "да" : "нет", expected ? "да" : "нет");
    free_tree(&root);
    return 0;
}

int main(void)
{
    int t1[] = {1, 2, 2, 3, 4, 4, 3};
    int t2[] = {1, 2, 2, NO_NODE, 3, NO_NODE, 3};
    int t3[] = {1, 2, 2, 3, NO_NODE, NO_NODE, 3};
    int t4[] = {1, 2, 3};
    int t5[] = {7};

    if (run_test(t1, 7, 1) != 0) return 1;
    if (run_test(t2, 7, 0) != 0) return 1;
    if (run_test(t3, 7, 1) != 0) return 1;
    if (run_test(t4, 3, 0) != 0) return 1;
    if (run_test(t5, 1, 1) != 0) return 1;
    if (run_test(t5, 0, 1) != 0) return 1;
    return 0;
}
