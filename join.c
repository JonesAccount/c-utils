/*

join — string concatenation function with memory reallocation.

Parameters:
- str1 — pointer to a pointer to the first string (will be modified); may point to NULL.
- str2 — string to append to the end of str1.

Return 0 on success, -1 on error.

Includes:
- string.h
- stdlib.h

How it works:
The function calculates the lengths of both strings and reallocates memory for *str1 to fit both. Then it copies str2 to the end of *str1 and adds the null terminator. If *str1 == NULL, the behavior is similar to strdup(str2). On realloc failure, the original pointer remains valid.

Example:
char *s = malloc(6);
strcpy(s, "Hello");

join(&s, ", World!"); // s == "Hello, World!"

free(s);

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

join — функция конкатенации строк с перевыделением памяти.

Параметры:
- str1 — указатель на указатель на первую строку (будет изменена); может указывать на NULL
- str2 — строка, которая добавляется в конец str1

Возвращает 0 при успехе, -1 при ошибке.

Подключить:
- string.h
- stdlib.h

Как работает:
Функция вычисляет длины обеих строк и перевыделяет память для *str1, чтобы вместить обе. Затем копирует str2 в конец *str1 и добавляет нулевой терминатор. Если *str1 == NULL, поведение аналогично strdup(str2). При неудаче realloc исходный указатель остаётся валидным.

Пример:
char *s = malloc(6);
strcpy(s, "Hello");

join(&s, ", World!"); // s == "Hello, World!"

free(s);

*/

int join(char **str1, char *str2) {
    if (!str1 || !str2 ) { return -1; }
    
    size_t first_string_length = (*str1) ? strlen(*str1) : 0;
    size_t second_string_length = strlen(str2);
    size_t combined_length = first_string_length + second_string_length;
    
    char *tmp = realloc(*str1, combined_length + 1);
    
    if (NULL == tmp) { return -1; }
    
    *str1 = tmp;
    
    memcpy(*str1 + first_string_length, str2, second_string_length);
    
    (*str1)[combined_length] = '\0';
    
    return 0;
} 
