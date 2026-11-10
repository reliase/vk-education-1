/*
 * Задача 5. Сравнение двух бинарных деревьев
 *
 * Даны два бинарных дерева.
 *
 * Необходимо определить, являются ли они идентичными (по структуре и
 * значениям узлов).
 */

#include <stdio.h>
#include "functions.h"

static int run_test(const int *a, int na, const int *b, int nb, int expected)
{
    TreeNode *ra, *rb;

    if (build_tree(a, na, &ra) != 0) {
        printf("ошибка: нет памяти\n");
        return -1;
    }
    if (build_tree(b, nb, &rb) != 0) {
        free_tree(&ra);
        printf("ошибка: нет памяти\n");
        return -1;
    }
    printf("A: ");
    print_tree(ra);
    printf("B: ");
    print_tree(rb);
    printf("  одинаковые: %s (ожидалось %s)\n",
           is_same_tree(ra, rb) ? "да" : "нет", expected ? "да" : "нет");
    free_tree(&ra);
    free_tree(&rb);
    return 0;
}

int main(void)
{
    int a1[] = {1, 2, 3},       b1[] = {1, 2, 3};
    int a2[] = {1, 2},          b2[] = {1, NO_NODE, 2};
    int a3[] = {1, 2, 1},       b3[] = {1, 1, 2};
    int a4[] = {4, 2, 6, 1, 3}, b4[] = {4, 2, 6, 1, 3};

    if (run_test(a1, 3, b1, 3, 1) != 0) return 1;
    if (run_test(a2, 2, b2, 3, 0) != 0) return 1;
    if (run_test(a3, 3, b3, 3, 0) != 0) return 1;
    if (run_test(a4, 5, b4, 5, 1) != 0) return 1;
    if (run_test(a1, 0, b1, 0, 1) != 0) return 1;
    if (run_test(a1, 1, b1, 0, 0) != 0) return 1;
    return 0;
}
