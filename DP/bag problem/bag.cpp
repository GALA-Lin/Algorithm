/*分数背包问题：
这是一个分数背包问题（物品可以分割），所以我们可以使用贪心算法。
策略：计算每个物品的单位价值（价值/重量），然后按照单位价值从大到小排序。
然后依次选择单位价值高的物品，直到背包装满。如果当前物品不能全部装入，则装入部分。
*/
#include <bits/stdc++.h>

using namespace std;

struct Item {
    double weight;
    double value;
    double unitValue;
};

bool compareItems(const Item &a, const Item &b) {
    return a.unitValue > b.unitValue;
}

int main() {
    int n;
    double C;
    while (cin >> n >> C) {
        vector<Item> items(n);
        for (int i = 0; i < n; i++) {
            cin >> items[i].weight;
        }
        for (int i = 0; i < n; i++) {
            cin >> items[i].value;
            items[i].unitValue = items[i].value / items[i].weight;
        }

        sort(items.begin(), items.end(), compareItems);

        double totalValue = 0.0;
        double remaining = C;

        for (int i = 0; i < n; i++) {
            if (remaining <= 0) break;
            if (items[i].weight <= remaining) {
                totalValue += items[i].value;
                remaining -= items[i].weight;
            } else {
                totalValue += remaining * items[i].unitValue;
                remaining = 0;
                break;
            }
        }

        cout << fixed << setprecision(1) << totalValue << endl;
    }
    return 0;
}