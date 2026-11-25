/*
 * Задача 3. K-й наименьший / наибольший элемент массива
 * Найти элемент через кучу из K кандидатов. K нумеруется с 1;
 * повторяющиеся значения занимают отдельные места.
 */
#include <stdio.h>
#include "functions.h"

int main(void)
{
    int arr[] = {7, -2, 7, 0, INT_MAX, INT_MIN};
    int sorted[] = {INT_MIN, -2, 0, 7, 7, INT_MAX};
    size_t k;
    int small, large;

    for (k = 1; k <= 6; k++) {
        if (kth_array(arr, 6, k, 0, &small) != 1
            || kth_array(arr, 6, k, 1, &large) != 1) return 1;
        printf("K = %zu: минимум %d (ожидалось %d), "
               "максимум %d (ожидалось %d)\n",
               k, small, sorted[k-1], large, sorted[6-k]);
        if (small != sorted[k-1] || large != sorted[6-k]) return 1;
    }
    if (kth_array(arr, 6, 0, 0, &small) != 0
        || kth_array(arr, 6, 7, 0, &small) != 0
        || kth_array(NULL, 0, 1, 0, &small) != 0) return 1;
    if (kth_array(arr, 1, 1, 0, &small) != 1 || small != 7) return 1;
    printf("Один элемент, пустой массив и неверные K: верно\n");
    return 0;
}
