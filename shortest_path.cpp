#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    // Add edge (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Shortest Path from source
    void shortestPath(int src) {
        vector<int> dist(V, -1);   // distance array
        vector<int> parent(V, -1); // to print path
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (dist[neigh] == -1) {
                    dist[neigh] = dist[node] + 1;
                    parent[neigh] = node;
                    q.push(neigh);
                }
            }
        }
        // Print shortest distances
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> Distance = " << dist[i] << endl;
        }

        int dest = V - 1;
        if (dist[dest] == -1) {
            cout << "\nNo path exists to node " << dest << endl;
            return;
        }

        cout << "\nPath from " << src << " to " << dest << ": ";
        vector<int> path;

        for (int v = dest; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    int source = 0;
    g.shortestPath(source);

    return 0;
}