#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000   // FIX: use integer
int main() {
    int N = 8;
    vector<vector<int>> graph = {
        {INF,1,2,5,INF,INF,INF,INF},
        {INF,INF,INF,INF,4,11,INF,INF},
        {INF,INF,INF,INF,9,5,16,INF},
        {INF,INF,INF,INF,INF,INF,2,INF},
        {INF,INF,INF,INF,INF,INF,INF,18},
        {INF,INF,INF,INF,INF,INF,INF,13},
        {INF,INF,INF,INF,INF,INF,INF,2},
        {INF,INF,INF,INF,INF,INF,INF,INF}
    };
    vector<int> cost(N, INF);
    cost[N-1] = 0;
    // Multistage Graph DP
    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            if (graph[i][j] != INF && cost[j] != INF) {
                if (graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                }
            }
        }
    }
    cout << "Minimum cost from source to destination = " << cost[0];
    return 0;
}