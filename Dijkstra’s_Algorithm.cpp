#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
void dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << "Dist to " << i << " = " << dist[i] << endl;
}
int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    dijkstra(V, adj, 0);
    return 0;
}