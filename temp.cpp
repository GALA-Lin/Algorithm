#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int h[N];
double p[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> h[i];

    p[0] = 1;

    double res = 0;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 2;
        res += 1.0 / p[i] * h[i];
    }

    cout << ceil(res) << endl;

    return 0;
}