#include <iostream>
using namespace std;

const int MAXN = 1000;
int n, m;
int a[MAXN][MAXN], pre[MAXN][MAXN];

void preSumX2() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
        }
    }
}

int main() {
    cin >> n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    preSumX2();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout <<"("<<x1<<","<<y1<<")"<< " to " << "("<<x2<<","<<y2<<")"<< " sum = " << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
    return 0;
}