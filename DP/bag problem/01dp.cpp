#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[1001],w[1001],f[1001][1001];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}