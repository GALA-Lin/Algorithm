// 查找给定点集的最小距离。
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
};

// 按X坐标排序的比较函数
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// 按Y坐标排序的比较函数
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// 计算两点之间的距离
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// 暴力方法，用于找到点集P中任意两点的最小距离
float bruteForce(Point P[], int n)
{
    float minDist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < minDist)
                minDist = dist(P[i], P[j]);
    return minDist;
}

// 返回两个浮点数中的较小值
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// 查找strip中点对的最小距离
// strip[]中的点按Y坐标排序，且所有点到中间线的距离小于d
float stripClosest(Point strip[], int size, float d)
{
    float minDist = d; // 初始化最小距离为d

    qsort(strip, size, sizeof(Point), compareY);

    // 遍历strip中的每个点，并尝试与后续点配对
    // 只要y坐标之差小于当前最小距离
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j)
            if (dist(strip[i], strip[j]) < minDist)
                minDist = dist(strip[i], strip[j]);

    return minDist;
}

// 递归函数，用于查找点集P的最小距离
float closestUtil(Point P[], int n)
{
    // 如果点数为2或3，使用暴力方法
    if (n <= 3)
        return bruteForce(P, n);

    // 找到中间点
    int mid = n / 2;
    Point midPoint = P[mid];

    // 计算中间线左侧的最小距离dl
    float dl = closestUtil(P, mid);
    // 计算中间线右侧的最小距离dr
    float dr = closestUtil(P + mid, n - mid);

    // 取dl和dr中的较小值为d
    float d = min(dl, dr);

    // 构建strip数组，包含所有距离中间线小于d的点
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // 查找strip中的最小距离，并与d比较，返回较小值
    return min(d, stripClosest(strip, j, d));
}

// 调用closestUtil()查找最小距离
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestUtil(P, n);
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    // 将vector转换为数组
    Point *P = &points[0];

    cout << "最小距离是 " << closest(P, n) << endl;
    return 0;
}