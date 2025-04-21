#include <iostream>
using namespace std;

int n, m, x, a[100001];
int flag;

int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l, r;
    while (m--)
    {
        flag = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                if (a[i] ^ a[j] == x)
                {
                    flag = 1;
                    printf("%d\n", a[i] ^ a[j]);
                }
            }
            if (flag == 1)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    // 请在此输入您的代码
    return 0;
}