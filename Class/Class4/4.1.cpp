#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int maxSoFar = 0; 
    int maxEndingHere = 0;

    for (int x : nums) {
        maxEndingHere += x;
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    int C;
    cin >> C; 

    while (C--) {
        int n;
        cin >> n; 

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i]; // Read the integers
        }
        cout << maxSubArraySum(nums) << endl;
    }

    return 0;
}
