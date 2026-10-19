/*
 * В школе прошёл экзамен по математике. Несколько человек списали решения
 * и получили 0 баллов.
 */
#include <stdio.h>
void zeros_end(int *arr, int n);
void swap(int *a, int *b);
int main(void){
    int arr[] = {0, 0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    zeros_end(arr, n);

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void zeros_end(int *arr, int n){
    int u1=0, u2=0;
    while (u2<n){
        if (arr[u2]!=0){
            swap (&arr[u1], &arr[u2]);
            u1++;
            }
            u2++;
        }
    }


/*
 * Почему решение стабильное:
 *   u2 встречает ненулевые элементы слева направо в исходном порядке,
 *   и каждый ставится на очередную позицию u1. Между u1 и u2 всегда лежат
 *   только нули, поэтому swap меняет ненулевой элемент с нулём и не
 *   перемешивает ненулевые.
 *
 * Время: O(n) — один проход u2 по массиву, каждый шаг O(1).
 * Память: O(1) — только индексы u1, u2 и tmp в swap.
 */
