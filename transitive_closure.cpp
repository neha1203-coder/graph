#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> tc; // transitive closure matrix
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        tc.resize(V, vector<int>(V, 0));
    }
    // Add directed edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    // DFS to mark reachable nodes
    void DFS(int src, int node) {
        tc[src][node] = 1;

        for (int neigh : adj[node]) {
            if (!tc[src][neigh]) {
                DFS(src, neigh);
            }
        }
    }
    // Compute transitive closure
    void transitiveClosure() {
        for (int i = 0; i < V; i++) {
            DFS(i, i); // start DFS from each node
        }
    }
    // Print matrix
    void printTC() {
        cout << "Transitive Closure Matrix:\n";

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << tc[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.transitiveClosure();
    g.printTC();

    return 0;
}