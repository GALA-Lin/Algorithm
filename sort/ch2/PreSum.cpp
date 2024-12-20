#include <iostream>
using namespace std;

const int MAXN = 1e5;
int n, a[MAXN], pre[MAXN];

void pre_sum() {
    pre[0] = a[0];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre_sum();
    for (int i = 1; i <= n; i++) {
        cout << pre[i] << " ";
    }
    int l,r;
    cin >> l >> r;
    cout << l <<"到"<<r<<"的和为：" << pre[r] - pre[l - 1];
    return 0;
}