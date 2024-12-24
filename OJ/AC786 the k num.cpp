// 第K个数 AC786
// 给定一个整数序列，求出第K大的数。

#include <iostream>
#include <algorithm>
using namespace std;
/* 解法一：全排序后输出第K个数, 时间复杂度O(nlogn)
void qsort(int a[], int left, int right)
{
    if (left >= right) return;
    int i=left-1,j=right+1,x=a[left];
    while (i<j)
    {
        do i++; while (a[i]<x);
        do j--; while (a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    qsort(a,left,j);
    qsort(a,j+1,right);
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    qsort(a, 0, n - 1);
    cout << a[k - 1] << endl;
    return 0;
}
*/
// 解法二：使用快速选择算法，时间复杂度O(n)
int partition(int a[], int left, int right, int pivot)
{
    int i = left, j = right;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
    return -1;
}
int quickSelect(int a[], int left, int right, int k)
{
    if (left == right)
        return a[left];
    int pivot = a[left + right >> 1];
    int pos = partition(a, left, right, pivot); // 找到pivot的位置
    if (pos == k - 1)
        return a[pos];
    else if (pos > k - 1)            // pivot在k左边
        return quickSelect(a, left, pos - 1, k);
    else                            // pivot在k右边
        return quickSelect(a, pos + 1, right, k);
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << quickSelect(a, 0, n - 1, k) << endl;
    return 0;
}