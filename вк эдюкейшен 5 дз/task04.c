/*
 * Задача 4. K-й наименьший / наибольший элемент в BST
 * Использовать свойства дерева поиска и симметричный либо обратный
 * симметричный обход. K нумеруется с 1.
 */
#include <stdio.h>
#include "functions.h"

static int run_test(const int *arr, size_t n, const int *sorted, size_t count)
{
    TreeNode *root;
    size_t k;
    int small, large, failed = 0;

    if (build_tree(arr, n, &root) != 0) return 1;
    print_tree(root);
    for (k = 1; k <= count; k++) {
        if (kth_bst(root, k, 0, &small) != 1
            || kth_bst(root, k, 1, &large) != 1) {
            failed = 1;
            break;
        }
        printf("  K = %zu: минимум %d, максимум %d\n", k, small, large);
        if (small != sorted[k-1] || large != sorted[count-k]) failed = 1;
    }
    if (kth_bst(root, 0, 0, &small) != 0
        || kth_bst(root, count+1, 0, &small) != 0) failed = 1;
    free_tree(&root);
    return failed;
}

int main(void)
{
    int a[] = {8, 3, 10, 1, 6, NO_NODE, 14};
    int sorted[] = {1, 3, 6, 8, 10, 14};
    int chain[] = {5, 3, NO_NODE, 2, NO_NODE, NO_NODE, NO_NODE, 1};
    int chain_sorted[] = {1, 2, 3, 5};

    if (run_test(a, 7, sorted, 6)) return 1;
    if (run_test(chain, 8, chain_sorted, 4)) return 1;
    if (run_test(a, 1, a, 1)) return 1;
    if (run_test(NULL, 0, NULL, 0)) return 1;
    return 0;
}
