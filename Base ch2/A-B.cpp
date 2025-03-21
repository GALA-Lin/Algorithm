#include <iostream>
#include <vector>
using namespace std;

// 判断a > b
bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) 
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--) 
        if (a[i] != b[i]) return a[i] > b[i];
    return true;
}

// 计算两个绝对值的差
vector<int> sub(vector<int> &a, vector<int> &b) {
    vector<int> res;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        carry = a[i] - carry;
        if (i < b.size()) carry -= b[i];
        res.push_back((carry + 10) % 10);
        if (carry < 0) carry = 1;
        else carry = 0;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a, b;
    bool isNegative1 = false, isNegative2 = false;

    // 处理第一个数是否为负数
    if (s1[0] == '-') {
        isNegative1 = true;
        s1 = s1.substr(1);
    }
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');

    // 处理第二个数是否为负数
    if (s2[0] == '-') {
        isNegative2 = true;
        s2 = s2.substr(1);
    }
    for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    if (isNegative1 && isNegative2) { // 两个数都是负数 cmp表示两绝对值大小
        if (cmp(a, b)) {                // 绝对值a>b 即a<b
            vector<int> res = sub(a, b);
            if(res[0]!= 0) printf("-");
            for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
        } 
        else {
            vector<int> res = sub(b, a);
            for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
        }
    } 
    else if (isNegative1) { // 第一个数是负数
        vector<int> res = sub(b, a);
        printf("-");
        for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
    }
    else if (isNegative2) { // 第二个数是负数
        vector<int> res = sub(a, b);
        for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
    } 
    else { // 两个数都是正数
        if (cmp(a, b)) {
            vector<int> res = sub(a, b);
            for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
        } 
        else {
            vector<int> res = sub(b, a);
            printf("-");
            for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
        }
    }
    return 0;
}
