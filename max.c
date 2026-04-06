
/*

max — function to find the maximum value in an array of integers.

Parameters:
- arr — the array to search
- size — number of elements in the array

Include:
- stddef.h
- limits.h

How it works:
The function iterates through all elements of the array and finds the largest one.
If the array is empty (size == 0), INT_MIN is returned as a signal that there are no elements.

Example:
int arr[] = {7, 3, 5, 1, 9, 2};
size_t size = sizeof(arr) / sizeof(arr[0]);

int maximum = max(arr, size); // 9

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

max — функция поиска максимального значения в массиве целых чисел.

Параметры:
- arr  — массив для поиска
- size — количество элементов в массиве

Подключить:
- stddef.h
- limits.h

Как работает:
Функция проходит по всем элементам массива и находит наибольшее.
Если массив пустой (size == 0), возвращается INT_MIN как сигнал отсутствия элементов.

Пример:
int arr[] = {7, 3, 5, 1, 9, 2};
size_t size = sizeof(arr) / sizeof(arr[0]);

int maximum = max(arr, size); // 9

*/

int max(int *arr, size_t size) {
        if (size == 0) { return INT_MIN; }

        int result = arr[0];

        for (size_t i = 1; i < size; i++) {
                if (arr[i] > result) {
                        result = arr[i];
                }
        }

        return result;
}