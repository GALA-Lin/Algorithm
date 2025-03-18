#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5 + 10;

ll a[N];
// A+B=A⊕B 
void solve() {
    ll n , x = 0; 
    cin >> n;
    for(ll i = 0 ; i < n ; i ++) {
        cin >> a[i];
        x |= a[i];
        printf("%lld ", x);
    }
    for(ll i = 0 ; i < 35; i ++) {
        if((x >> i & 1) == 0) {
            cout << (1 << i) << '\n';
            return ;
        }
    }
}

int main() {
    ll _ = 1;
    while(_ --) {
        solve();
    }
    return 0; // 添加返回语句
}
