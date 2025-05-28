#include <iostream>
#include <vector>

using namespace std;

int integer_partition(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));// dp[i][j] 表示从 i 个数中取 j 个数的划分方式

    // 初始化 dp 数组
    for (int i = 0; i <= n; ++i) {
        dp[i][1] = 1; // 只能划分为 1+1+...+1 的形式
        dp[1][i] = 1; // 只划分为一个数字 n 时，只有一种划分方式
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (i < j) {
                dp[i][j] = dp[i][i];
            } else if (i == j) {
                dp[i][j] = dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n;
    cin >> n;
    vector<int> results;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        results.push_back(integer_partition(num));
    }

    for (const auto &result : results) {
        cout << result << endl;
    }

    return 0;
}
