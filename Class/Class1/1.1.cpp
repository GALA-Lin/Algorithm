#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int l, int r, unordered_set<string> &result) {
    if (l == r) {
        result.insert(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r, result);
            swap(s[l], s[i]); // backtrack
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        string input;
        cin >> input;
        unordered_set<string> result;
        permute(input, 0, n - 1, result);

        // Convert the set to a vector and sort it
        vector<string> sortedResult(result.begin(), result.end());
        sort(sortedResult.begin(), sortedResult.end());

        // Output each permutation
        for (const string &perm : sortedResult) {
            cout << perm << endl;
        }

        // Output the total number of permutations
        cout << sortedResult.size() << endl;
    }
    return 0;
}
