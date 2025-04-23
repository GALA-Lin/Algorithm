#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int main(){
    long long a[N],temp_l,n,c,length=0;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int l=i+1,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid]-a[i]>=c)r=mid;
            else l=mid +1;
        }
        if(a[l]-a[i]==c)temp_l=l;
        else continue;
        l=temp_l-1,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            if(a[mid]<=a[temp_l])l=mid;//已经找到符合条件的索引，再在这个索引后找==a[索引的]
            else r=mid-1;
        }
        length+=l-temp_l+1;
    }
    cout<<length;
}