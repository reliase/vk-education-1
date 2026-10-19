/*
 * Дан массив, состоящий из 0, 1 и 2.
 * Необходимо отсортировать его за линейное время.
 */
#include <stdio.h>
void swap(int *a, int *b);
void sort_colors(int *arr, int n);

int main(void){
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    sort_colors(arr, n);

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
void sort_colors(int *arr, int n){
    int low = 0, mid = 0, high = n-1;
    while (mid <= high){
        if (arr[mid] == 0){
            swap( &arr[low], &arr[mid]);
            low ++;
            mid ++;
        }else if (arr[mid] == 1){
            mid ++;
        }else{
            swap( &arr[mid], &arr[high]);
            high --;
        }
    }
}

/*
 * Как поддерживаются границы:
 *   слева от low — нули, от low до mid — единицы, от mid до high —
 *   ещё не просмотрено, справа от high — двойки.
 *   0 — swap с low, low++ и mid++; 1 — mid++; 2 — swap с high, high--
 *   (mid не сдвигаем: пришедший с high элемент ещё не проверен).
 *
 * Время: O(n) — каждый шаг сокращает непросмотренную зону на 1.
 * Память: O(1) — только индексы low, mid, high и tmp в swap.
 */
