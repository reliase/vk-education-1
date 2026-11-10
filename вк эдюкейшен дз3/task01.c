/*
 * Задача 1. Найти корень числа (ближайшее целое)
 *
 * Необходимо написать функцию, которая находит целую часть квадратного
 * корня числа (округление вниз).
 */

#include <stdio.h>
#include "functions.h"

int main(void)
{
    long long tests[] = {0, 1, 2, 3, 4, 8, 9, 15, 16, 17, 24, 25, 1000000,
                         999999999999LL, 9223372036854775807LL, -5};
    int count = (int)(sizeof(tests) / sizeof(tests[0]));
    int i;

    for (i = 0; i < count; i++) {
        printf("sqrt(%lld) = %lld\n", tests[i], int_sqrt(tests[i]));
    }
    return 0;
}
