/*
  int func1(int x) {
	int _port(int y){
	 return x+y;
	 }
	return _port;
	}
*/
#include <stdio.h>

int func1(void) {
	int x=11;
	return x;
	}
int sum(int x, int y) // в функцию передаются два целых числа
{
  int k = x + y;  // вычисляем сумму чисел и сохраняем в k
  return k;       // возвращаем значение k
}
 //указатель на функцию (замыкание)
 int func2(int x){ return x + 100; }
int func3(int (*funcA)(int), int x){ return funcA(x) ; }

//###   //###   //###   //###   //###
// uint16_t (целый без знаковый тип размером в 16 бит)
int usr_ABS(int value){return (value > 0)?(value):(-value);}
// функция которая возводит в квадрат
int usr_POW2(int value) { return value*value; }
int (*funcF)(int);       // Указатель

int main()
{
  int r;
  int f;
  f=func1(); 
  printf("f= %d\n", f); // вывод:  f
  r = sum(7, 8);    // вызов функции: x=a, y=5
  printf("r= %d\n", r); // вывод:  r
  printf("func3=  %d\n", func3(func2, 11) );  // 100+11=111
  
  // Присваиваем указателю адрес на функцию usr_ABS
  // Кстати говоря можно делать и так func = usr_ABS, 
  // так как просто имя функции и будет означать её адрес
    funcF = &usr_ABS;

    printf("%d\n", usr_ABS(-20)); // выводит 20 использую функцию
    printf("%d\n", (*funcF)(-20)); // выводит 20 использую указатель

    funcF = &usr_POW2; // а теперь указывает на usr_POW2

    printf("%d\n", usr_ABS(30));   // выводит 30
    printf("%d\n", usr_ABS(-30));   // выводит 30
    printf("%d\n", (*funcF)(30));   // выводит 900
  
  return 0;  
}

