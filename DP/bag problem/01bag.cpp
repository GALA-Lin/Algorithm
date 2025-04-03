#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[1001],w[1001],f[1001][1001];
//二维DP
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];//f[i][j]表示前i件物品恰好装入容量为j的背包可以获得的最大价值
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
            //f[i][j]表示前i件物品恰好装入容量为j的背包可以获得的最大价值
            //状态转移方程：如果不放第i件物品，则f[i][j]等于f[i-1][j]；如果放第i件物品，则f[i][j]等于max(f[i][j],f[i-1][j-v[i]]+w[i])
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
/*一维DP
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX(a,b) (a>b?a:b)

int main() {
    int N, V;
    cin >> N >> V;
    int v[1001], w[1001], state[1001] = {0}; // 初始化state数组为0
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= v[i]; j--) {
            state[j] = max(state[j], state[j - v[i]] + w[i]);
        // 状态转移方程： 表示容量为j的背包可以承载的最大价值
        // 如果不放第i件物品，则最大价值等于state[j]
        // 如果放第i件物品，则最大价值等于state[j - v[i]] + w[i]
        }
    }
    cout << state[V] << endl;
    return 0;
}
*/