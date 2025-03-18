#include <iostream>
using namespace std;

int main()
{
  int cont = 0;
  for(int i = 1;i<=2020;i++){
    for(int j =i; j>0;j /= 10){
      if(j%10==2) cont++;
    }
  }
  printf("%d",cont);
  return 0;
}