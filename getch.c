/*

getch — function for reading a single character from the keyboard without the need to press Enter and without displaying the character on the console.

Parameters:
None

Include:
<stdio.h>
<termios.h>
<unistd.h>

How it works:
The function saves the current terminal settings, disables canonical mode (ICANON) and input echoing (ECHO), reads a single character from the keyboard using getchar(), and then restores the previous terminal settings. Returns the read character.

Example:
#include <stdio.h>

char ch = getch(); // Reads one character, e.g., 'a'
printf("You pressed: %c\n", ch);

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

getch — функция для считывания одного символа с клавиатуры без необходимости нажимать Enter и без отображения символа в консоли.

Параметры:
Нет параметров

Подключить:
<stdio.h>
<termios.h>
<unistd.h>

Как работает:
Функция сохраняет текущие настройки терминала, отключает канонический режим (ICANON) и отображение вводимых символов (ECHO), считывает один символ с клавиатуры с помощью getchar(), а затем восстанавливает старые настройки терминала. Возвращает считанный символ.

Пример:
#include <stdio.h>

char ch = getch(); // Считан один символ, например 'a'
printf("Вы нажали: %c\n", ch);

*/

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}