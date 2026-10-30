/*
 * В исходную строку добавили некоторое количество символов. Необходимо
 * определить, была ли строка a исходной для строки b.
 */
#include <stdio.h>
#include <string.h>
int is_subsequence(const char *a, const char *b);

int main(void){
    printf("%d\n", is_subsequence("abd", "abcd"));
    printf("%d\n", is_subsequence("abd", "uabqd"));
    printf("%d\n", is_subsequence("ooo", "abcd"));
    printf("%d\n", is_subsequence("", "abcd"));

    return 0;
}
int is_subsequence(const char *a, const char *b){
    int i = 0;
    int j = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);

    while (i < len_a && j < len_b){
        if (a[i] == b[j]){
            i++;
        }
        j++;
    }
    return i == len_a;
}


/*
 * i идёт по a, j - по b. Символы совпали - двигаем оба, иначе только j
 * (символ b[j] добавлен). Если i дошёл до конца a, все символы a найдены
 * в b в том же порядке, значит a - исходная строка для b.
 *
 * Время: O(len_a + len_b) - один проход.
 * Память: O(1) - два индекса.
 */
