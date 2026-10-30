/*
 * Дан отсортированный массив чисел и целевое число target. Необходимо
 * определить, существуют ли два элемента, сумма которых равна target.
 */
#include <stdio.h>
int two_sum(const int *arr, int n, int target);

int main(void){
    int arr[] = {3, 8, 9, 11, 16, 18, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", two_sum(arr, n, 25));
    printf("%d\n", two_sum(arr, n, 40));
    printf("%d\n", two_sum(arr, n, 6));

    return 0;
}
int two_sum(const int *arr, int n, int target){
    int left = 0;
    int right = n - 1;

    while (left < right){
        if (arr[left] + arr[right] == target){
            return 1;
        } else if (arr[left] + arr[right] > target){
            right--;
        } else{
            left++;
        }
    }
    return 0;
}


/*
 * Сумма больше target - правый элемент слишком велик, двигаем right влево.
 * Меньше - левый слишком мал, двигаем left вправо. Подходящая пара при
 * этом не теряется.
 *
 * Время: O(n) - каждый шаг сдвигает один указатель, не больше n шагов.
 * Память: O(1) - два индекса.
 */
