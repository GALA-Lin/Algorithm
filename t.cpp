#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

int fun(int n){
    int temp=1;
    while(n){
        temp *=n;
        n--;
    }
    return temp;
}

signed main() {
    // 请在此处编写代码...
    int n;cin>>n;
    cout<<fun(n)<<endl;
    return 0;
}