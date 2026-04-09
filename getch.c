/*

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