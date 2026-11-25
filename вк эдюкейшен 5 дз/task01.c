/*
 * Задача 1. Полное бинарное дерево
 * Проверить заполненность всех уровней, кроме последнего, и заполнение
 * последнего уровня слева направо. Использовать обход BFS.
 */
#include <stdio.h>
#include "functions.h"

static int run_test(const int *arr, size_t n, int expected)
{
    TreeNode *root;
    int result;

    if (build_tree(arr, n, &root) != 0) return 1;
    print_tree(root);
    result = is_complete(root);
    printf("  полное: %d (ожидалось %d)\n", result, expected);
    free_tree(&root);
    return result != expected;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {1, 2, 3, 4, NO_NODE, 6, 7};
    int d[] = {1, NO_NODE, 2};
    int e[] = {1, 2, 3, 4, 5, NO_NODE, 7};

    if (run_test(a, 7, 1) || run_test(b, 6, 1)) return 1;
    if (run_test(c, 7, 0) || run_test(d, 3, 0)) return 1;
    if (run_test(e, 7, 0) || run_test(a, 2, 1)) return 1;
    if (run_test(a, 1, 1) || run_test(NULL, 0, 1)) return 1;
    return 0;
}
