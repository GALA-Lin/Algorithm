#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

// 快速幂函数
long long fast_pow(long long base, long long exp) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        long long d = (long long)a * b % mod * c % mod; // 计算初始的d值
        long long temp = fast_pow(d, n); // 使用快速幂计算d^n % mod
        cout << temp % mod << endl;
    }

    return 0;
}
