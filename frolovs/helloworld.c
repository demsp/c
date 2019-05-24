// Cannot Create D:\tc\Bin\tcdef.dpr
// Cannot Create D:\tc\Bin\tcdef.dsk
// Cannot Create D:\tc\Bin\tcconfig.tc
// clear the "read only" attribute of these files and it will goes on fine. 
// ввод и вывод несколько раз буферизируются. getchar() действительно читает по одному символу, но не напрямую с клавы, 
// а из буфера ввода, в который символы попадают из другого буфера после того, как в нём символ '\n' повстречается.

// Вместо getchar() надо использовать getch() из conio.h
// Это небуферизованный ввод одного символа. 

#include <stdio.h>
#include <conio.h>
int main(void)
{
printf("Hello World!!!\n");
getch();
return 0;
}
