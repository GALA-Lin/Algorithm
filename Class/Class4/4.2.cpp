#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; 
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int L = 2; L <= n; L++) { 
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[0][n - 1]; 
}

int main() {
    int C;
    cin >> C; 

    while (C--) {
        int n;
        cin >> n; 
        vector<int> dimensions(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> dimensions[i]; 
        }
        cout << matrixChainOrder(dimensions) << endl;
    }

    return 0;
}
