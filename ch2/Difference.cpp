#include <iostream>
using namespace std;
const int MAXN = 1001;
int n;
int arr[MAXN],diff[MAXN];

void difference(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        diff[i] = arr[i] - arr[i-1];
    }
}
void insert(int l, int c) {
    diff[l]   += c;
    diff[l+1] -= c;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
/*
    // calculate the difference array
    difference(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << diff[i] << " ";
    }
    cout << endl;
*/
    // insert the original array into the difference array
    for(int i=1;i<=n;i++)
        insert(i,arr[i]);
    cout << "After insert:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << diff[i] << " ";
    }
    return 0;
}
    