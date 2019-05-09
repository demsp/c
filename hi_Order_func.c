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
 //указатель на функцию (pfvsrfybt)
 int func2(int x){ return x + 100; }
int func3(int (*_func)(int), int x){ return _func(x) ; }
int main()
{
  int r;
  int f;
  f=func1(); 
  printf("f= %d\n", f); // вывод:  f
  r = sum(7, 8);    // вызов функции: x=a, y=5
  printf("r= %d\n", r); // вывод:  r
  printf("func3=  %d\n", func3(func2, 11));  // 100
  return 0;  // поэтому getchar() вызываем дважжы
}

/*
#include <stdio.h>
int f(int x){ return x + 3; }
int g(int (*func)(int), int x){ return func(x) * func(x); }
//printf("%d", g(f, 7));
int main(int argc, char **argv)
{
	printf("%d", g(f, 7));  // 100
	return 0;
}
*/
