#include <bits/stdc++.h>
using namespace std;

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}


int main() {
    int arr[1001];
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}