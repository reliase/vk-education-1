#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits.h>

#define NO_NODE INT_MIN

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int build_tree(const int *arr, int n, TreeNode **root);
void free_tree(TreeNode **root);
void print_tree(const TreeNode *root);

int is_symmetric(const TreeNode *root);
int min_depth(const TreeNode *root);
int bst_min_max_product(const int *arr, int n, long long *res);
int is_same_tree(const TreeNode *a, const TreeNode *b);

#endif
