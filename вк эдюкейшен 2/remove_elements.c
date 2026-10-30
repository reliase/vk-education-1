/*
 * Необходимо написать функцию, которая принимает односвязный список и
 * целое число val. Нужно удалить узел, значение которого равно val.
 */
#include <stdio.h>
struct node{
    int val;
    struct node *next;
};
struct node *build_list(struct node *nodes, const int *vals, int n);
void print_list(const struct node *head);
struct node *remove_elements(struct node *head, int val);

int main(void){
    int vals[] = {7, 7, 1, 2, 7, 3};
    int n = sizeof(vals) / sizeof(vals[0]);
    struct node nodes[sizeof(vals) / sizeof(vals[0])];
    struct node *head;

    head = build_list(nodes, vals, n);
    print_list(head);

    head = remove_elements(head, 7);
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
struct node *remove_elements(struct node *head, int val){
    struct node dummy;
    struct node *prev;
    struct node *cur;

    dummy.next = head;
    prev = &dummy;
    cur = head;
    while (cur != NULL){
        if (cur->val == val){
            prev->next = cur->next;
        } else{
            prev = cur;
        }
        cur = cur->next;
    }
    return dummy.next;
}


/*
 * Перед головой стоит dummy, поэтому у каждого узла (и у головы) есть
 * prev, и удаление везде одинаковое: prev->next = cur->next. Если удалена
 * голова, меняется dummy.next - его и возвращаем как новую голову.
 *
 * Время: O(n) - один проход.
 * Память: O(1) - dummy и два указателя.
 */
