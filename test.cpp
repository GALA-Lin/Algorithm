#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a="A",b;
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){  // n>=2时 
		b = a;
		b.push_back('A'+i-1); // STL,在字符串 b后插入一个字符 
		a = b+a;
	}
	cout<<a<<endl;
	return 0; 
} 
