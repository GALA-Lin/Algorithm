#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> alls;
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        alls.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(alls.begin(), alls.end());
    for(int i=0;i<alls.size();i++)
        cout<<alls[i]<<" ";
    cout<<endl;
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去重
    for (int i = 0; i < n; i++)
    {
        int pos = find(a[i]);
        cout << pos << " ";
    }
    return 0;
}
