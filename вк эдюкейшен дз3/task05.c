/*
 * Задача 5. Сумма двух элементов массива
 *
 * Дан неотсортированный массив целых чисел и число target.
 * Необходимо найти два элемента массива, сумма которых равна target.
 * Каждый элемент можно использовать только один раз.
 * Если подходящей пары нет — вернуть пустой массив.
 */

#include <stdio.h>
#include "functions.h"

static void run_test(const int *data, int n, int target)
{
    int i1, i2, res, i;

    printf("[");
    for (i = 0; i < n; i++) {
        printf("%s%d", i > 0 ? ", " : "", data[i]);
    }
    printf("], target = %d -> ", target);

    res = two_sum(data, n, target, &i1, &i2);
    if (res == 1) {
        printf("[%d, %d] (%d + %d)\n", i1, i2, data[i1], data[i2]);
    } else if (res == 0) {
        printf("[]\n");
    } else {
        printf("ошибка: нет памяти\n");
    }
}

int main(void)
{
    int d1[] = {3, 9, -2, 11, 7, 15};
    int d2[] = {5, 5};
    int d3[] = {3};
    int d4[] = {2147483647, -2147483647 - 1, 1};
    int d5[] = {4, 1, 8, 6, 3};

    run_test(d1, 6, 18);
    run_test(d1, 6, 100);
    run_test(d2, 2, 10);
    run_test(d3, 1, 6);
    run_test(d4, 3, -1);
    run_test(d5, 5, 9);
    return 0;
}
