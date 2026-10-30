/*
 * Напишите функцию, которая принимает строку и возвращает 1, если она
 * является палиндромом (слово или текст, одинаково читающиеся в обоих
 * направлениях). В противном случае верните 0.
 */
#include <stdio.h>
#include <string.h>
int is_palindrome(const char *s);

int main(void){
    printf("%d\n", is_palindrome("abcba"));
    printf("%d\n", is_palindrome("abba"));
    printf("%d\n", is_palindrome("abca"));
    printf("%d\n", is_palindrome("a"));
    printf("%d\n", is_palindrome(""));

    return 0;
}
int is_palindrome(const char *s){
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right){
        if (s[left] != s[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}


/*
 * Сравниваем символы с концов к центру: s[left] и s[right]. Первое
 * несовпадение - не палиндром. Указатели встретились - палиндром.
 *
 * Время: O(n) - не больше n/2 сравнений.
 * Память: O(1) - два индекса.
 */
