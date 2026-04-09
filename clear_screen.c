/*

clear_screen — function to clear the terminal screen.

Parameters:
None

Include:
<stdio.h>

How it works:
The function sends ANSI codes to the terminal: \033[2J clears the screen, and \033[H moves the cursor to position (0,0) — the top-left corner. Then fflush(stdout) ensures that these commands are immediately sent to the terminal.

Example:
#include <stdio.h>

printf("Hello, C!");
clear_screen(); // Clears the screen

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

clear_screen — функция для очистки экрана терминала.

Параметры:
Нет параметров

Подключить:
<stdio.h>

Как работает:
Функция отправляет ANSI-коды в терминал: \033[2J очищает экран, а \033[H перемещает курсор в позицию (0,0) — верхний левый угол. Затем fflush(stdout) гарантирует вывод этих команд в терминал.

Пример:
#include <stdio.h>

printf("Hello, C!"):
clear_screen(); // Очистка экрана

*/

void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}