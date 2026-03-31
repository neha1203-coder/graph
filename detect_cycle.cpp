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
    // BFS Cycle Detection
    bool BFS_Cycle(int start, vector<bool> &visited) {
        queue<pair<int, int>> q; // {node, parent}

        visited[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, node});
                }
                else if (neighbour != parent) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }
    // Check for cycle in whole graph
    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (BFS_Cycle(i, visited))
                    return true;
            }
        }
        return false;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // cycle
    g.addEdge(3, 4);

    if (g.hasCycle())
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}