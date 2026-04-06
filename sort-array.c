/*

sort_array — function for sorting an integer array.

Parameters:
- arr   — array to sort
- size  — number of elements
- ascending — 1 for ascending order, 0 for descending order

Headers required:
- stdio.h
- stddef.h

How it works:
Two nested loops compare all pairs of elements and swap them
if the order is violated.
No new array is created — the original is modified in place.

Example:
int arr[] = {7, 3, 5, 1, 9, 2};
size_t size = sizeof(arr) / sizeof(arr[0]);

sort_array(arr, size, 1); // {1, 2, 3, 5, 7, 9}
sort_array(arr, size, 0); // {9, 7, 5, 3, 2, 1}

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 
sort_array — функция сортировки массива целых чисел.

Параметры:
- arr — массив для сортировки
- size — количество элементов
- ascending — 1 по возрастанию, 0 по убыванию

Подключить:
- stdio.h
- stddef.h

Как работает:
Два вложенных цикла сравнивают все пары элементов и меняют их местами, если порядок нарушен.
Новый массив не создаётся — исходный изменяется напрямую.

Пример:
int arr[] = {7, 3, 5, 1, 9, 2};
size_t size = sizeof(arr) / sizeof(arr[0]);

sort_array(arr, size, 1); // {1, 2, 3, 5, 7, 9}
sort_array(arr, size, 0); // {9, 7, 5, 3, 2, 1}

*/

void sort_array(int *arr, size_t size, int ascending) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if ((arr[j] < arr[i]) == ascending) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
