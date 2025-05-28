#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int INF = numeric_limits<int>::max();

// Prim算法构造最小生成树
vector<pair<int, int>> prim(int n, vector<vector<int>>& graph) {
    vector<int> visited(n, 0); // 记录顶点是否已被加入生成树
    vector<int> minDist(n, INF); // 每个顶点到生成树的最短距离
    vector<int> parent(n, -1); // 记录每个顶点的父节点
    minDist[0] = 0; // 从顶点0开始

    // 优先队列，按距离最小的顺序弹出
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // 起始顶点

    while (!pq.empty()) {
        int u = pq.top().second; // 当前顶点
        pq.pop();

        if (visited[u]) continue; // 如果顶点已被访问，跳过
        visited[u] = 1;

        // 遍历与顶点u相邻的顶点
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && !visited[v]) { // 如果顶点v未被访问且有边
                if (graph[u][v] < minDist[v]) {
                    minDist[v] = graph[u][v];
                    parent[v] = u;
                    pq.push({minDist[v], v});
                }
            }
        }
    }

    // 构造生成树的边
    vector<pair<int, int>> mst;
    for (int i = 1; i < n; ++i) {
        mst.push_back({parent[i], i});
    }
    return mst;
}

int main() {
    // 定义图的邻接矩阵
    int n = 5;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][1] = 25; graph[1][0] = 25; // A-B: 25
    graph[0][2] = 5; graph[2][0] = 5; // A-C: 5
    graph[0][3] = 25; graph[3][0] = 25; // A-D: 25
    graph[0][4] = 45; graph[4][0] = 45; // A-E: 45
    graph[1][2] = 7; graph[2][1] = 7; // B-C: 7
    graph[1][3] = 11; graph[3][1] = 11; // B-D: 11
    graph[1][4] = 12; graph[4][1] = 12; // B-E: 12
    graph[2][3] = 44; graph[3][2] = 44; // C-D: 44
    graph[2][4] = 34; graph[4][2] = 34; // C-E: 34
    graph[3][4] = 78; graph[4][3] = 78; // D-E: 78

    // 使用Prim算法构造最小生成树
    vector<pair<int, int>> mst = prim(n, graph);

    // 输出最小生成树的边
    cout << "Prim算法构造的最小生成树：" << endl;
    for (const auto& edge : mst) {
        cout << char('A' + edge.first) << "-" << char('A' + edge.second) << endl;
    }

    return 0;
}
