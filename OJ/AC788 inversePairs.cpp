//查找逆序对
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*解法一 双指针 O(n^2)
int inversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                count[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += count[i];
    }
    return ans;
}
*/

/*解法二 归并排序+二分查找  O(nlogn)*/
int inversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n + 1, 0);
    mergeSort(nums, 0, n - 1, count);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += count[i];
    }
    return ans;
}

void mergeSort(vector<int>& nums, int left, int right, vector<int>& count) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }
}

void merge(vector<int>& nums, int left, int mid, int right, vector<int>& count) {
    
    vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            count[nums[i]] += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (int i = left; i <= right; i++) {
        nums[i] = temp[i - left];
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << inversePairs(nums) << endl;
    return 0;
}