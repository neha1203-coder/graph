#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);

    for (auto row : dist) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}