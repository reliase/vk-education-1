/*
 * Необходимо написать функцию, которая принимает на вход односвязный
 * список и разворачивает его.
 */
#include <stdio.h>
struct node{
    int val;
    struct node *next;
};
struct node *build_list(struct node *nodes, const int *vals, int n);
void print_list(const struct node *head);
struct node *reverse_list(struct node *head);

int main(void){
    int vals[] = {1, 2, 3, 4};
    int n = sizeof(vals) / sizeof(vals[0]);
    struct node nodes[sizeof(vals) / sizeof(vals[0])];
    struct node *head;

    head = build_list(nodes, vals, n);
    print_list(head);

    head = reverse_list(head);
    print_list(head);

    return 0;
}
struct node *build_list(struct node *nodes, const int *vals, int n){
    int i;

    if (n == 0){
        return NULL;
    }
    for (i = 0; i < n; i++){
        nodes[i].val = vals[i];
        nodes[i].next = (i + 1 < n) ? &nodes[i + 1] : NULL;
    }
    return &nodes[0];
}
void print_list(const struct node *head){
    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
struct node *reverse_list(struct node *head){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


/*
 * prev - уже развёрнутая часть, current - текущий узел, next - запомненный
 * остаток списка. На каждом шаге ссылка current разворачивается назад
 * (current->next = prev). В конце prev - новая голова.
 *
 * Время: O(n) - каждый узел обрабатывается один раз.
 * Память: O(1) - три указателя.
 */
