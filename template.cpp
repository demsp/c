#include <iostream>
    //using namespace std;
    // шаблон функции
    template <class X> void swap(X &a, X &b)
    {
    X temp;
    temp = a;
    a = b;
    b = temp;
    }
    int main()
    {
    int i=10; int j = 20;
    float x=10.1; 
    float y=23.3;
    char a='x'; char b='z';
    std::cout << "Original i, j: " << i << ' ' << j << std::endl;
    std::cout << "Original x, y: " << x << ' ' << y << std::endl;
    std::cout << "Original a, b: " << a << ' ' << b << std::endl;
    swap(i, j); // обмен целых
    swap(x, y); // обмен вещественных значений
    swap(a, b); // обмен символов
    std::cout << "Swapped i, j : " << i << ' ' << j << std::endl;
    std::cout << "Swapped x, y: " << x << ' ' << y << std::endl;
    std::cout << "Swapped a, b: " << a << ' ' << b << std::endl;
    return 0;
    }
