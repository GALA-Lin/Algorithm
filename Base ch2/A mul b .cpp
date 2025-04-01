#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int> &a, int b){
    vector<int> res;
    int t = 0;
    for(int i=0; i<a.size()||t; i++){
        if(i<a.size()) t += a[i]*b;
        res.push_back(t%10);
        t /= 10;
    }
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i=a.size()-1; i>=0; i--) A.push_back(a[i]-'0');
    vector<int> res = mul(A, b);
    for(int i=res.size()-1; i>=0; i--) cout << res[i];
    return 0;
}