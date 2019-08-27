// http://ermak.cs.nstu.ru/cprog/html/076.htm

#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>


int calc(char *s){
std:: cout << s << " ";	
int inside=0;                                                      // уровень вложенности ()
int n;

char *p1=NULL,*p2=NULL;                                 // указатели на символы операций + и * вне ()
//char *q;

for (char *q=s;*q!=NULL;q++)
            switch(*q)
                        {
case '*':
case '/': if (inside==0 && p2==NULL) p2=q;
                                    break;                           // Запоминание первой * вне ()
case '+':
case '-': if (inside==0 && p1==NULL) p1=q;
                                    break;                           // Запоминание первго + вне ()
case '(': inside++; break;
case ')': inside--; break;
                        }
                        
if (p1!=NULL) p2=p1;                                          // Запоминание самой низкоприоритетной
if (p2!=NULL){                                                    // операции
            char c=*p2; *p2=0;                                 // "разрезать" строку на две части
            switch(c)                                               // и выполнить операцию над результатом
                        {                                               // для полученных частей
case '*': return calc(s) * calc(p2+1);
case '/': return calc(s) / calc(p2+1);
case '+':            return calc(s) + calc(p2+1);
case '-': return calc(s) - calc(p2+1);
                        }}
/*                         
if (*s=='(' && *(q-1)==')'){                         // выражение в () - снять ()
            *(q-1)=0; return calc(s+1);                       // и вызвать рекурсивно для выражения в ()
            }                                                           // накопление константы
for ( n=0;*s>='0' && *s<='9';s++)            n=n*10+*s-'0';
*/
  
    return n;
    
    }               
            
int main(void){
	char char_arr[] = "3+2+1";
	calc(char_arr);
	//std::	cout << calc(char_arr);
	return 0;
	
	}            
