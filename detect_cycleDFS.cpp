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
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool DFS(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (DFS(neighbour, node, visited))
                    return true;
            }
            else if (neighbour != parent) {
                return true; // cycle found
            }
        }
        return false;
    }
    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, -1, visited))
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