/*
#include <stdio.h>
int sum(int x, int y) // в функцию передаются два целых числа
{
  int k = x + y;  // вычисляем сумму чисел и сохраняем в k
  return k;       // возвращаем значение k
}
int main()
{
  int r;
  r = sum(6, 5);    // вызов функции
  printf("r= %d", r); // вывод:  r
  return 0; 
}
*/
#include <stdio.h>
int f(int x){ return x + 3; }
int g(int (*func)(int), int x){ return func(x) * func(x); }

int main(int argc, char **argv)
{
	printf("%d", g(f, 7));  // 100
	return 0;
}
