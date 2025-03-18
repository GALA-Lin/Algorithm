#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int m=1,flag=0;
  while(m++)
{
  for(int i=0;i<n;i++)
  {
  if((a[i]+m)!=(a[i]^m))
  break;
  else
  flag++;
  }
  if(flag==n)
  break;
}
cout<<m;
  return 0;
}