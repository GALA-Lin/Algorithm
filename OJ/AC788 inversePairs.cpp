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
void merge(vector<int>& nums, int left, int mid, int right, int& count) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            count += mid - i + 1; // 直接累加逆序对的数量
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (int i = 0; i < temp.size(); i++) {
        nums[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int left, int right, int& count) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }
}

int inversePairs(vector<int>& nums) {
    int n = nums.size();
    int count = 0; // 使用一个整数来累加逆序对的数量
    mergeSort(nums, 0, n - 1, count);
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << inversePairs(nums) << endl;
    return 0;
}