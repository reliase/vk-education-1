/*
 * Задача 4. Найти разницу между двумя строками
 *
 * Даны строки a и b.
 * Строка b получена из строки a путём перемешивания символов и добавления
 * одной новой буквы.
 * Необходимо вернуть эту добавленную букву.
 */

#include <stdio.h>
#include "functions.h"

int main(void)
{
    const char *tests[][2] = {
        {"uio", "oeiu"},
        {"fe", "efo"},
        {"ab", "ab"},
        {"bbb", "bbbb"},
        {"", "z"},
        {"abcd", "dcbae"}
    };
    int count = (int)(sizeof(tests) / sizeof(tests[0]));
    int i;
    char r1, r2;

    for (i = 0; i < count; i++) {
        r1 = extra_letter_count(tests[i][0], tests[i][1]);
        r2 = extra_letter_xor(tests[i][0], tests[i][1]);
        printf("a = \"%s\", b = \"%s\" -> подсчёт: %c, XOR: %c\n",
               tests[i][0], tests[i][1], r1 ? r1 : '-', r2 ? r2 : '-');
    }
    return 0;
}
