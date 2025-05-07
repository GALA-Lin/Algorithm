#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;  // 使用更具描述性的常量名

int longestIncreasingSubsequence(int arr[], int size) {
    int dp[MAX_N] = {0};  // 初始化dp数组为0，避免使用memset可能带来的问题
    int maxLen = 1;       // 使用更具描述性的变量名

    // 初始化dp数组，每个元素的最长递增子序列至少为1（自己）
    for (int i = 0; i < size; ++i) {
        dp[i] = 1;
    }

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;  // 更新dp[i]，使其成为以arr[i]结尾的最长递增子序列的长度
            }
        }
        maxLen = max(maxLen, dp[i]);  // 使用max函数来更新maxLen
    }
    return maxLen;
}

int main() {
    int arr[MAX_N];
    int length;

    cin >> length;
    for (int i = 0; i < length; ++i) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, length) << endl;
    return 0;
}
