#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, wt;
};
bool isNegativeCycle(int V, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    // Assume source = 0
    dist[0] = 0;
  
    for (int i = 1; i <= V - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }
    for (auto e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
            return true; // Negative cycle exists
        }
    }
    return false;
}
int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 1, -1}
    };
    if (isNegativeCycle(V, edges))
        cout << "Negative Cycle Detected\n";
    else
        cout << "No Negative Cycle\n";
    return 0;
}