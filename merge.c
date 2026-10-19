/*
 * Дано два отсортированных массива. Необходимо написать функцию, которая
 * объединит эти два массива в один отсортированный.
 */
#include <stdio.h>
void merge (int *arr, int n, int *arr2, int p, int *res);

int main(void){
    int a[] = {3, 8, 10, 11};
    int b[] = {1, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int p = sizeof(b) / sizeof(b[0]);
    int res[sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0])];
    int i;

    merge(a, n, b, p, res);

    for (i = 0; i < n + p; i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
void merge (int *arr, int n, int *arr2, int p, int *res){
    int u1 =0, u2=0, u3=0;
      while ( u1 < n && u2 < p){
        if (arr[u1]<=arr2[u2]){
            res[u3]=arr[u1];
            u3++;
            u1++;
        } else{
            res[u3]=arr2[u2];
            u3++;
            u2++;
        }
    }
        while (u1<n){
            res[u3]=arr[u1];
            u3++;
            u1++;
        }
        while (u2<p){
            res[u3]=arr2[u2];
            u3++;
            u2++;
        }


      

}

/*
 * Почему порядок корректный:
 *   оба массива отсортированы, и на каждом шаге в res идёт меньший из
 *   arr[u1] и arr2[u2], поэтому res заполняется по возрастанию. Остаток
 *   второго массива уже отсортирован — дописываем без сравнений.
 *   <= при равенстве берёт из arr первым — слияние стабильно.
 *
 * Время: O(n + p) — каждый шаг записывает в res ровно один элемент.
 * Память: O(1) дополнительной — только u1, u2, u3 (res — это ответ).
 */
