#include <iostream>

using namespace std;

int quick_select(int a[], int left, int right, int k)
{
    if(left == right)
        return a[left];
    int i = left, j = right, pivot = a[left];
    while(i < j)
    {
        while(i < j && a[j] >= pivot)
            j--;
        a[i] = a[j];
        while(i < j && a[i] < pivot)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    if(i == k)
        return a[i];
    else if(i < k)
        return quick_select(a, i+1, right, k);
    else
        return quick_select(a, left, i-1, k);
}

int main()
{
    int n,a[10001];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int target;
    target = quick_select(a,0,n-1,n/2);
    cout << target << endl;
    return 0;
}