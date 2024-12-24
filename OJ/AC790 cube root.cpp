#include <iostream>
#include <cmath>
using namespace std;
/*解法一：利用pow函数求立方根 or cbrt函数求立方根
int main() {
    double x;
    cin >> x;
    double cube_root1 = pow(x, 1.0/3.0);
    double cube_root2 = cbrt(x);
    cout << cube_root1 << endl;
    cout << cube_root2 << endl;
    return 0;
}
*/
//解法二：二分法求立方根
int main() {
    double x;
    cin >> x;
    double left = -1e9, right = 1e9, mid;
    while (right - left > 1e-8) {
        mid = (left + right) / 2;
        if (mid * mid * mid - x < 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%lf\n", mid);
    return 0;
}