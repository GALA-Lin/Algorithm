#include <iostream>
#include <vector>
using namespace std;

int LCS(string s1, string s2) {
    int m = s1.length();  // s1的长度
    int n = s2.length();  // s2的长度
    // 使用vector初始化二维数组
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

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
    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << LCS(s1, s2) << endl;
    
    return 0;
}
