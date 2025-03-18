#include <bits/stdc++.h>
using namespace std;
string pre,aim;

void turnChar(int i){
    if(pre[i]=='*') pre[i]='o';
    else pre[i]='*';
}

int main(){
    cin>>pre>>aim;
    int ans=0;
    int n = pre.length();
    for(int i=0;i<n;i++){
        if(pre[i]!=aim[i]){
            turnChar(i),turnChar(i+1);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}