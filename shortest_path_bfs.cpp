#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // {neighbour, weight}
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    // Add edge (undirected)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // 0-1 BFS
    void zeroOneBFS(int src) {
        vector<int> dist(V, 1e9);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (auto it : adj[node]) {
                int neigh = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[neigh]) {
                    dist[neigh] = dist[node] + wt;

                    if (wt == 0)
                        dq.push_front(neigh); // higher priority
                    else
                        dq.push_back(neigh);
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> " << dist[i] << endl;
        }
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 0);

    int source = 0;
    g.zeroOneBFS(source);

    return 0;
}