/*
 * Задача 2. Объединение K отсортированных массивов
 * Объединить массивы в один отсортированный, используя мин-кучу.
 * Сохранять повторяющиеся элементы, учитывать пустые массивы.
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

static int run_test(const int *const *arrays, const size_t *sizes,
                    size_t k, const int *expected, size_t expected_n)
{
    int *out, failed = 0;
    size_t n, i;

    if (merge_k_arrays(arrays, sizes, k, &out, &n) != 0) return 1;
    if (n != expected_n) failed = 1;
    printf("K = %zu -> [", k);
    for (i = 0; i < n; i++) {
        printf("%s%d", i ? ", " : "", out[i]);
        if (i >= expected_n || out[i] != expected[i]) failed = 1;
    }
    printf("] — %s\n", failed ? "ошибка" : "верно");
    free(out);
    return failed;
}

int main(void)
{
    int a[] = {-5, 1, 4}, b[] = {-3, 1, 8}, c[] = {0, 2};
    const int *arrays[] = {a, NULL, b, c};
    size_t sizes[] = {3, 0, 3, 2}, empty[] = {0, 0, 0, 0};
    int expected[] = {-5, -3, 0, 1, 1, 2, 4, 8};
    int extremes[] = {INT_MIN, 0, INT_MAX};
    const int *single[] = {extremes};
    size_t one_size[] = {3};

    if (run_test(arrays, sizes, 4, expected, 8)) return 1;
    if (run_test(single, one_size, 1, extremes, 3)) return 1;
    if (run_test(arrays, empty, 4, NULL, 0)) return 1;
    if (run_test(NULL, NULL, 0, NULL, 0)) return 1;
    return 0;
}
