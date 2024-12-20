#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b){
    vector<int> res;
    if(a.size() < b.size()) return add(b, a);
    int carry = 0;
    for(int i = 0; i < a.size(); i++){
        carry += a[i];
        if (i < b.size()) carry += b[i];
        res.push_back(carry % 10);
        carry /= 10;
    }
    if(carry > 0) res.push_back(carry);
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<int> a;
    vector<int> b;
    //convert char to int
    for(int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for(int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');
    auto c = add(a, b);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl;
    return 0;
}

