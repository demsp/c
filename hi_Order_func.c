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
	int x=10;
	return x;
	}
int sum(int x, int y) // в функцию передаются два целых числа
{
  int k = x + y;  // вычисляем сумму чисел и сохраняем в k
  return k;       // возвращаем значение k
}

//###   //###   //###   //###   //###
// uint16_t (целый без знаковый тип размером в 16 бит)
int usr_ABS(int value){return (value > 0)?(value):(-value);}
// функция которая возводит в квадрат
int usr_POW2(int value) { return value*value; }

int (*funcA)(int);       // Указатель

//указатель на функцию (замыкание)
 int func2(int x){ return x + 100; }
int func3(int (*funcB)(int), int x){ return funcB(x) ; }

int main()
{
  int r;
  int f;
  f=func1(); 
  r = sum(7, 8);    // вызов функции
  printf("f= %d\n", f); // вывод:  f = 10
  printf("r= %d\n", r); // вывод:  r = 7+8 =15
   // Присваиваем указателю адрес на функцию usr_ABS
  // Кстати говоря можно делать и так func = usr_ABS, 
  // так как просто имя функции и будет означать её адрес
    funcA = &usr_ABS;
      printf("%d\n", usr_ABS(-20)); // выводит 20 использую функцию
      printf("%d\n", (*funcA)(-20)); // выводит 20 использую указатель
    funcA = &usr_POW2; // а теперь указывает на usr_POW2
      printf("%d\n", usr_ABS(30));   // выводит 30
      printf("%d\n", usr_ABS(-30));   // выводит 30
      printf("%d\n", (*funcA)(30));   // выводит 900
      
     // funcB 
     printf("func3=  %d\n", func3(func2, 11) );  // 100+11=111  
  
  return 0;  
}

