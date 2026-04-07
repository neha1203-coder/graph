#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
bool detectNegativeCycle(vector<vector<int>>& dist, int V) {
    // Floyd-Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // Check diagonal
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0)
            return true;
    }
    return false;
}
int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0, 1, INF, INF},
        {INF, 0, -1, INF},
        {INF, INF, 0, -1},
        {-1, INF, INF, 0}
    };
    if (detectNegativeCycle(dist, V))
        cout << "Negative Cycle Detected\n";
    else
        cout << "No Negative Cycle\n";
    return 0;
}