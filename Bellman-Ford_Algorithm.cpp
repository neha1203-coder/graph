#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, wt;
};
int main() {
    int V = 5;
    vector<Edge> edges = {
        {0,1,2}, {0,2,4}, {1,2,1}, {1,3,7}, {2,4,3}, {3,4,1}
    };
    vector<int> dist(V, 1e9);
    dist[0] = 0;
    for (int i = 1; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] + e.wt < dist[e.v])
                dist[e.v] = dist[e.u] + e.wt;
        }
    }
    for (int i = 0; i < V; i++)
        cout << "Dist to " << i << " = " << dist[i] << endl;
    return 0;
}