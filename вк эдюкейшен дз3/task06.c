/*
 * Задача 6. Массив анаграмм
 *
 * Дан массив строк strs. Сгруппируйте анаграммы вместе. Вы можете вернуть
 * ответ в любом порядке.
 *
 * Анаграмма — это слово или фраза, полученная путем перестановки букв
 * другого слова или фразы, обычно с использованием всех исходных букв
 * ровно один раз.
 *
 * Пример:
 *   ["eat","tea","tan","ate","nat","bat"]
 *   -> [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Алгоритм нужно выбрать самим и стремиться сделать наиболее эффективно.
 */

#include <stdio.h>
#include "functions.h"

int main(void)
{
    const char *w1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    const char *w2[] = {"won", "now", "aaa", "ooo", "ooo"};
    const char *w3[] = {""};
    const char *w4[] = {"a"};
    const char *w5[] = {"listen", "silent", "enlist", "google", "gogole",
                        "inlets", "abc", "cab", "bca", "xyz"};

    if (group_anagrams(w1, 6) != 0) return 1;
    if (group_anagrams(w2, 5) != 0) return 1;
    if (group_anagrams(w3, 1) != 0) return 1;
    if (group_anagrams(w4, 1) != 0) return 1;
    if (group_anagrams(w5, 10) != 0) return 1;
    return 0;
}
