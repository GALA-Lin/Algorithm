#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计算中位数
int findMedian(vector<int>& points) {
    int size = points.size();
    if (size % 2 == 0) {
        return (points[size / 2 - 1] + points[size / 2]) / 2;
    } else {
        return points[size / 2];
    }
}

// 计算所有居民点到邮局的最小曼哈顿距离之和
int minDistanceSum(vector<pair<int, int>>& residents) {
    vector<int> xCoords, yCoords;
    for (const auto& resident : residents) {
        xCoords.push_back(resident.first);
        yCoords.push_back(resident.second);
    }

    // 对坐标进行排序
    sort(xCoords.begin(), xCoords.end());
    sort(yCoords.begin(), yCoords.end());

    // 找到x和y坐标的中位数
    int medianX = findMedian(xCoords);
    int medianY = findMedian(yCoords);

    // 计算曼哈顿距离之和
    int minDistance = 0;
    for (const auto& resident : residents) {
        minDistance += abs(resident.first - medianX) + abs(resident.second - medianY);
    }

    return minDistance;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // 如果n为0，结束输入

        vector<pair<int, int>> residents(n);
        for (int i = 0; i < n; ++i) {
            cin >> residents[i].first >> residents[i].second;
        }

        int result = minDistanceSum(residents);
        cout << result << endl;
    }

    return 0;
}
