/*
 * Дан односвязный список. Необходимо найти его середину за O(n) без
 * дополнительных аллокаций.
 */
#include <stdio.h>
struct node{
    int val;
    struct node *next;
};
struct node *build_list(struct node *nodes, const int *vals, int n);
struct node *middle_node(struct node *head);

int main(void){
    int vals1[] = {3, 8, 9, 6, 11, 16, 17};
    int vals2[] = {1, 2, 3, 4};
    struct node nodes1[sizeof(vals1) / sizeof(vals1[0])];
    struct node nodes2[sizeof(vals2) / sizeof(vals2[0])];
    struct node *head1;
    struct node *head2;

    head1 = build_list(nodes1, vals1, sizeof(vals1) / sizeof(vals1[0]));
    head2 = build_list(nodes2, vals2, sizeof(vals2) / sizeof(vals2[0]));

    printf("%d\n", middle_node(head1)->val);
    printf("%d\n", middle_node(head2)->val);

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
struct node *middle_node(struct node *head){
    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


/*
 * fast проходит два узла за шаг, slow - один. Когда fast дошёл до конца,
 * slow прошёл ровно половину и стоит на середине. При чётной длине
 * вернётся второй из двух средних узлов.
 *
 * Время: O(n) - один проход.
 * Память: O(1) - два указателя.
 */
