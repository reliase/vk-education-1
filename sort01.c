/*
 * Дан массив, содержащий только 0 и 1.
 * Написать функцию, которая сортирует его так, чтобы все нули оказались
 * в начале, а единицы — в конце.
 * Решение должно быть in-place.
 */
#include <stdio.h>
void swap(int *a, int *b);
void sort01(int *arr, int n);

int main(void){
    int arr[] = {0, 1, 1, 0, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    sort01(arr, n);

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
void sort01(int *arr, int n){
    int left = 0, right = n-1;
    while (left < right){
        if (arr[left] == 0){
            left ++;
        }else if (arr[right] == 1){
            right --;
        }else{
            swap( &arr[left], &arr[right]);
            left ++;
            right --;
        }
    }
}

/*
 * Время: O(n)
 *   На каждой итерации хотя бы один из индексов сдвигается на 1 навстречу
 *   другому, а расстояние между ними в начале n-1. Значит итераций не
 *   больше n-1, каждая за O(1), и массив проходится один раз.
 *
 * Память: O(1)
 *   Только два индекса left, right и переменная tmp в swap, новый массив
 *   не создаётся.
 */
