/*
 * Написать функцию, которая принимает два отсортированных односвязных
 * списка и объединяет их в один отсортированный список. Затраты по
 * памяти должны быть O(1).
 */
#include <stdio.h>
struct node{
    int val;
    struct node *next;
};
struct node *build_list(struct node *nodes, const int *vals, int n);
void print_list(const struct node *head);
struct node *merge_lists(struct node *list1, struct node *list2);

int main(void){
    int vals1[] = {3, 6, 8};
    int vals2[] = {4, 7, 9, 11};
    struct node nodes1[sizeof(vals1) / sizeof(vals1[0])];
    struct node nodes2[sizeof(vals2) / sizeof(vals2[0])];
    struct node *list1;
    struct node *list2;
    struct node *res;

    list1 = build_list(nodes1, vals1, sizeof(vals1) / sizeof(vals1[0]));
    list2 = build_list(nodes2, vals2, sizeof(vals2) / sizeof(vals2[0]));

    res = merge_lists(list1, list2);
    print_list(res);

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
struct node *merge_lists(struct node *list1, struct node *list2){
    struct node dummy;
    struct node *tail = &dummy;

    dummy.next = NULL;
    while (list1 != NULL && list2 != NULL){
        if (list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
        } else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1 != NULL){
        tail->next = list1;
    } else{
        tail->next = list2;
    }
    return dummy.next;
}


/*
 * tail - конец результата (сначала dummy). Сравниваем головы списков и
 * подцепляем меньшую к tail->next. Остаток непустого списка подцепляется
 * одной ссылкой. Новые узлы не создаются, меняются только ссылки.
 *
 * Время: O(n + m) - каждый узел переходит в результат один раз.
 * Память: O(1) - dummy и три указателя.
 */
