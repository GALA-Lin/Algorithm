#include <bits/stdc++.h>
using namespace std;

int fun(int i){
    if(i==1) return 1;
    if(i==2) return 2;
    if(i==3) return 3;
    else return fun(i-2)+fun(i-1);
}

int main(){
    int n;cin>>n;
    cout<<fun(n);
    return 0;
}