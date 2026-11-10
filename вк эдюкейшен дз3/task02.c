/*
 * Задача 2. Очень лёгкая задача (два ксерокса)
 *
 * Как быстро можно сделать N копий документа, если есть два ксерокса,
 * каждый копирует с разной скоростью — x и y минут за копию?
 */

#include <stdio.h>
#include "functions.h"

int main(void)
{
    long long tests[][4] = {
        {4, 1, 1, 3},
        {5, 1, 2, 4},
        {1, 3, 5, 3},
        {2, 1, 5, 2},
        {10, 3, 3, 18},
        {100, 7, 2, 156}
    };
    int count = (int)(sizeof(tests) / sizeof(tests[0]));
    int i;
    long long res;

    for (i = 0; i < count; i++) {
        res = copy_time(tests[i][0], tests[i][1], tests[i][2]);
        printf("N = %lld, x = %lld, y = %lld -> %lld (ожидалось %lld)\n",
               tests[i][0], tests[i][1], tests[i][2], res, tests[i][3]);
    }
    return 0;
}
