#include <iostream>

using namespace std;

int main(){
int arr [5] = { 1, 2, 3, 4, 5 }; 

char string[100];
int num = 0,
index = 0;

//cout <<"Input: ";
cin >>string;

num = string[0] ;//- '0';

//num -= string[index + 1] - '0';

if (string[0]  == '+') {
arr[0]=arr[0]+10;
}
else{cout <<"Error " ;}

  for (int  i=0 ; i<5 ; i++ )
  {
    cout<<arr[i]<<" " ;
  }

return 0;
}
