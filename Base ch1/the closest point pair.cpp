#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
};

bool compareX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool compareY(const Point &p1, const Point &p2) { return p1.y < p2.y; }
float dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(vector<Point> &P) {
    float minDist = FLT_MAX;
    for (size_t i = 0; i < P.size(); ++i)
        for (size_t j = i + 1; j < P.size(); ++j)
            minDist = min(minDist, dist(P[i], P[j]));
    return minDist;
}

float stripClosest(vector<Point> &strip, float d) {
    sort(strip.begin(), strip.end(), compareY);
    float minDist = d;
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j)
            minDist = min(minDist, dist(strip[i], strip[j]));
    return minDist;
}

float closestUtil(vector<Point> &P) {
    int n = P.size();
    if (n <= 3) return bruteForce(P);
    vector<Point> Pl(P.begin(), P.begin() + n / 2);
    vector<Point> Pr(P.begin() + n / 2, P.end());
    float dl = closestUtil(Pl);
    float dr = closestUtil(Pr);
    float d = min(dl, dr);
    vector<Point> strip;
    for (auto &p : P)
        if (abs(p.x - P[n / 2].x) < d)
            strip.push_back(p);
    return min(d, stripClosest(strip, d));
}

float closest(vector<Point> &P) {
    sort(P.begin(), P.end(), compareX);
    return closestUtil(P);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto &p : points) cin >> p.x >> p.y;
    cout << "最小距离是 " << closest(points) << endl;
    return 0;
}