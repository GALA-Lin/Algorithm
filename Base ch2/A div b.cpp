#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 将一个大数（以向量形式存储）除以一个整数b，并返回商的向量形式，同时通过引用参数r返回余数
vector<int> div(vector<int> &a, int b, int &r){
    vector<int> res;
    r = 0;
    for(int i= a.size()-1; i >=0; i--){    // 从最高位开始计算
        r = r*10 + a[i];        // 更新余数，将当前位加入
        res.push_back(r/b);      // 计算商，向量形式存储
        r = r%b;                 // 更新余数
    }
    reverse(res.begin(), res.end());
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string s;
    cin>>s;
    vector<int> a;
    for(int i=s.size()-1; i>=0; i--) a.push_back(s[i]-'0');
    int b ;
    cin>>b;
    int r;
    vector<int> res = div(a, b, r);
    for(int i=res.size()-1; i>=0; i--) cout<<res[i];
    cout<<endl;
    return 0;
}