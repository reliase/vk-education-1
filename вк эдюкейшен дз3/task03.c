/*
 * Задача 3. Накормить животных
 *
 * В зоопарке есть животные, каждое из которых требует определённое
 * количество еды (целое число).
 * Каждая привезённая порция еды может накормить только одно животное
 * и не делится.
 *
 * Необходимо определить, сколько животных можно накормить имеющимся
 * набором порций.
 */

#include <stdio.h>
#include "functions.h"

static void print_array(const int *arr, int n)
{
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%s%d", i > 0 ? ", " : "", arr[i]);
    }
    printf("]");
}

static void run_test(int *animals, int na, int *food, int nf, int expected)
{
    printf("животные ");
    print_array(animals, na);
    printf(", еда ");
    print_array(food, nf);
    printf(" -> %d (ожидалось %d)\n",
           feed_animals(animals, na, food, nf), expected);
}

int main(void)
{
    int a1[] = {3, 4, 7},    f1[] = {8, 1, 2};
    int a2[] = {3, 8, 1, 4}, f2[] = {1, 1, 2};
    int a3[] = {1, 2, 2},    f3[] = {7, 1};
    int a4[] = {8, 2, 3, 2}, f4[] = {1, 4, 3, 8};
    int a5[] = {5, 5, 5},    f5[] = {1, 2, 3};

    run_test(a1, 3, f1, 3, 1);
    run_test(a2, 4, f2, 3, 1);
    run_test(a3, 3, f3, 2, 2);
    run_test(a4, 4, f4, 4, 3);
    run_test(a5, 3, f5, 3, 0);
    return 0;
}
