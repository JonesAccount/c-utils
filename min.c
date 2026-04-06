/*

min — функция поиска минимального значения в массиве целых чисел.

Параметры:
- arr — массив для поиска
- size — количество элементов в массиве

Подключить:
- stddef.h
- limits.h

Как работает:
Функция проходит по всем элементам массива и находит наименьшее.
Если массив пустой (size == 0), возвращается INT_MAX как сигнал отсутствия элементов.

Пример:
int arr[] = {7, 3, 5, 1, 9, 2};
size_t size = sizeof(arr) / sizeof(arr[0]);

int minimum = min(arr, size); // 1

*/

int min(int *arr, size_t size) {
        if (size == 0) { return INT_MAX; }

        int result = arr[0];

        for (size_t i = 1; i < size; i++) {
                if (arr[i] < result) {
                        result = arr[i];
                }
        }

        return result;
}