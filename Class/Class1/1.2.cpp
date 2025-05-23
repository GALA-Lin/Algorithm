#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    while (cin >> n >> x) {
        unordered_map<int, int> numCount;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            numCount[num]++;
        }

        if (numCount.find(x) != numCount.end()) {
            cout << x << " " << numCount[x] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
