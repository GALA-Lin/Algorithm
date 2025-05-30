#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c;
    while (cin >> n >> c) {
        vector<int> v(n), w(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
        vector<vector<bool>> path(n + 1, vector<bool>(c + 1, false));

        for (int i = 1; i <= n; i++) {
            int wi = w[i - 1];
            int vi = v[i - 1];
            for (int j = 1; j <= c; j++) {
                if (wi > j) {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = false;
                } else {
                    if (dp[i - 1][j] >= dp[i - 1][j - wi] + vi) {
                        dp[i][j] = dp[i - 1][j];
                        path[i][j] = false;
                    } else {
                        dp[i][j] = dp[i - 1][j - wi] + vi;
                        path[i][j] = true;
                    }
                }
            }
        }

        int max_value = dp[n][c];
        cout << max_value << endl;

        vector<int> ans(n, 0);
        int j = c;
        for (int i = n; i > 0; i--) {
            if (path[i][j]) {
                ans[i - 1] = 1;
                j -= w[i - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}