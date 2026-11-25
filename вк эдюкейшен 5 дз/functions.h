#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits.h>
#include <stddef.h>

/* Представление массива: дети i имеют индексы 2*i+1 и 2*i+2.
 * NO_NODE обозначает отсутствие узла, поэтому INT_MIN здесь не ключ. */
#define NO_NODE INT_MIN

typedef struct TreeNode {
    int data;
    int balance_factor;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int build_tree(const int *arr, size_t n, TreeNode **root);
void free_tree(TreeNode **root);
void print_tree(const TreeNode *root);

/* 1 / 0 — да / нет; -1 — ошибка выделения памяти. */
int is_complete(const TreeNode *root);
/* 0 — успех, -1 — ошибка аргументов, размера или памяти.
 * Результат принадлежит вызывающему коду; пустой результат — NULL. */
int merge_k_arrays(const int *const *arrays, const size_t *sizes,
                   size_t k, int **out, size_t *out_n);
/* k начинается с 1; largest != 0 выбирает k-й наибольший.
 * Повторы считаются отдельными элементами. 1 — найден, 0 — неверный k,
 * -1 — ошибка аргументов или памяти. */
int kth_array(const int *arr, size_t n, size_t k, int largest, int *out);
int kth_bst(const TreeNode *root, size_t k, int largest, int *out);
/* Заполняет balance_factor = height(left) - height(right).
 * Возвращает высоту в узлах: пустое дерево 0, лист 1. */
int fill_balance_factors(TreeNode *root);
void mirror_tree(TreeNode *root);

#endif
