#include<bits/stdc++.h>
using namespace std;
int N,M;
int dp[1001];
int v[1001],w[1001];

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        cin>>v[i]>>w[i];
    for(int i=1;i<=N;i++)
        for(int j=v[i];j<=M;j++){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    cout<<dp[M];
    return 0;
}