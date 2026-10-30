/*
 * Дан отсортированный массив. Необходимо удалить дубликаты in-place так,
 * чтобы каждый элемент встречался только один раз. Функция возвращает
 * новую длину массива.
 */
#include <stdio.h>
int remove_duplicates(int *arr, int n);

int main(void){
    int arr[] = {1, 1, 2, 2, 2, 3, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    n = remove_duplicates(arr, n);

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
int remove_duplicates(int *arr, int n){
    int slow = 0;
    int fast;

    if (n == 0){
        return 0;
    }
    for (fast = 1; fast < n; fast++){
        if (arr[fast] != arr[slow]){
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}


/*
 * Равные элементы идут подряд. fast ищет новое значение, slow - позиция
 * последнего уникального. Нашли новое - записываем его на slow + 1.
 * Дубликаты перезаписываются на месте, второй массив не нужен.
 *
 * Время: O(n) - один проход.
 * Память: O(1) - два индекса.
 */
