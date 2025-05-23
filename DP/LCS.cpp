#include <vector>
#include <iostream>

using namespace std;

void printDPMatrix(const vector<vector<int>>& dp, int m, int n) {
    // 函数实现
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int LCS(const string& s1, const string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {  // 遍历s1中的每个字符
        for (int j = 1; j <= n; j++) {  // 遍历s2中的每个字符
            if (s1[i-1] == s2[j-1]) {  // 如果当前字符相同
                dp[i][j] = dp[i-1][j-1] + 1;  // LCS长度加1
            } else {
                // 如果当前字符不同，选择不包括当前字符的最长LCS
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printDPMatrix(dp, m, n);
    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Length of LCS: "<<"\n" << LCS(s1, s2) << endl;
    return 0;
}
