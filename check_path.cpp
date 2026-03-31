#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge (undirected graph)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS to check path
    bool DFS(int src, int dest, vector<bool> &visited) {
        if (src == dest)
            return true;

        visited[src] = true;

        for (int neighbour : adj[src]) {
            if (!visited[neighbour]) {
                if (DFS(neighbour, dest, visited))
                    return true;
            }
        }
        return false;
    }
    // Function to check path
    bool hasPath(int src, int dest) {
        vector<bool> visited(V, false);
        return DFS(src, dest, visited);
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    int src = 0, dest = 5;

    if (g.hasPath(src, dest))
        cout << "Path exists between " << src << " and " << dest;
    else
        cout << "No path exists between " << src << " and " << dest;

    return 0;
}