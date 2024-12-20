#include <iostream>
using namespace std;

void binary_search1(int arr[], int low, int high, int x) {
    while (low <= high)
    {
        int mid = low + high >> 1;
        if (arr[mid] == x)
        {
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Element not found in array" << endl;
}
void binary_search2(int arr[], int low, int high, int x) {
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Element not found in array" << endl;
}


int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    binary_search1(arr, 0, n - 1, x);
    binary_search2(arr, 0, n - 1, x);
    return 0;
}
