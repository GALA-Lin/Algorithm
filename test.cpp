#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 活动结构体，包含开始时间和结束时间
struct Activity {
    int start, end;
};

// 比较函数，用于按结束时间排序
bool compareActivities(const Activity &a, const Activity &b) {
    return a.end < b.end;
}

// 计算最多可以安排的活动数量
int maxActivities(vector<Activity> &activities) {
    // 按照活动结束时间排序
    sort(activities.begin(), activities.end(), compareActivities);
    
    int count = 0;
    int lastEnd = -1;
    
    for (const auto &activity : activities) {
        // 如果当前活动的开始时间不早于上一个选择的活动的结束时间，则可以安排
        if (activity.start >= lastEnd) {
            count++;
            lastEnd = activity.end;
        }
    }
    
    return count;
}

int main() {
    int k;
    while (cin >> k) {
        vector<Activity> activities(k);
        for (int i = 0; i < k; i++) {
            cin >> activities[i].start >> activities[i].end;
        }
        
        cout << maxActivities(activities) << endl;
    }
    
    return 0;
}
    