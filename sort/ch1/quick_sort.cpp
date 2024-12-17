#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] >= pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}