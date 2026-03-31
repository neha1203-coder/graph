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
    // DFS helper
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                DFS(neighbour, visited);
            }
        }
    }

    // Count components
    int countComponents() {
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;          // new component found
                DFS(i, visited);  // visit all nodes of this component
            }
        }

        return count;
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Number of Connected Components: ";
    cout << g.countComponents();

    return 0;
}