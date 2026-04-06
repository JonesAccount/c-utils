/*

fill_random — function for filling an integer array with random numbers.

Parameters:
- arr  — array to fill
- size — number of elements in the array
- min  — minimum random value
- max  — maximum random value

Headers required:
- stdlib.h
- time.h
- stddef.h

How it works:
The function validates the input: array is not NULL, size is greater than 0,
range is valid (min <= max).
The random number generator is seeded only once on the first call
(a static flag variable "seeded" is used).
The array is then filled with random numbers in the range [min, max].
No new array is created — the original is modified in place.

Example:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

int main(void) {
    int arr[10];
    size_t size = sizeof(arr) / sizeof(arr[0]);

    fill_random(arr, size, 1, 10);

    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}



fill_random — функция заполнения массива целых чисел случайными числами.

Параметры:
- arr — массив для заполнения
- size — количество элементов в массиве
- min — минимальное значение случайного числа
- max — максимальное значение случайного числа

Подключить:
- stdlib.h 
- time.h 
- stddef.h 

Как работает:
Функция проверяет входные данные: массив не NULL, размер больше 0, диапазон корректный (min ≤ max).
Генератор случайных чисел инициализируется только один раз при первом вызове функции (используется статическая переменная-флаг seeded).
Затем массив заполняется случайными числами в диапазоне [min, max]. Новый массив не создаётся — исходный изменяется напрямую.

Пример:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

int main(void) {
    int arr[10];
    size_t size = sizeof(arr) / sizeof(arr[0]);

    fill_random(arr, size, 1, 10);

    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

*/

void fill_random(int *arr, size_t size, int min, int max) {
    if (NULL == arr || size == 0 || min > max ) { return; }
    
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    
}
