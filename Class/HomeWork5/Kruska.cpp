#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 并查集（Union-Find）结构
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

// 每条边的结构
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Kruskal算法构造最小生成树
vector<pair<int, int>> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(n);
    vector<pair<int, int>> mst;
    for (const auto& edge : edges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);
        if (rootU != rootV) {
            uf.unionSet(rootU, rootV);
            mst.emplace_back(edge.u, edge.v);
        }
    }
    return mst;
}

int main() {
    // 定义图的边
    int n = 5;
    vector<Edge> edges = {
        Edge(0, 1, 25), Edge(0, 2, 5),Edge(0, 3, 25), Edge(0, 4, 45),
        Edge(1, 2, 7), Edge(1, 3, 11), Edge(1, 4, 12),
        Edge(2, 3, 44), Edge(2, 4, 34),
        Edge(3, 4, 78)
    };

    // 使用Kruskal算法构造最小生成树
    vector<pair<int, int>> mst = kruskal(n, edges);

    // 输出最小生成树的边
    cout << "Kruskal算法构造的最小生成树：" << endl;
    for (const auto& edge : mst) {
        cout << char('A' + edge.first) << "-" << char('A' + edge.second) << endl;
    }

    return 0;
}
