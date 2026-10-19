/*
 * Дан массив целых чисел. Необходимо повернуть (сдвинуть) справа налево
 * часть массива, которая указана параметром k.
 * Решение должно работать за линейное время без дополнительных аллокаций.
 */
#include <stdio.h>
void reverse(int *arr, int left, int right);
void swap(int *a, int *b);
void rotate(int *arr, int n, int k);
int main (void){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int i;

    rotate(arr, n, k);

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
void reverse(int *arr, int left, int right){
    while( left < right){
        swap( &arr[left], &arr[right]);
        right --;
        left ++;
    }

}
void rotate(int *arr, int n, int k){
    if (n == 0){
        return;
    }
    k = k % n;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

}
