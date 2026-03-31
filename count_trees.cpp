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
    // Add edge (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // DFS to count nodes and edges
    void DFS(int node, vector<bool> &visited, int &nodes, int &edges) {
        visited[node] = true;
        nodes++;

        for (int neigh : adj[node]) {
            edges++;            // count edge
            if (!visited[neigh]) {
                DFS(neigh, visited, nodes, edges);
            }
        }
    }
    // Count trees in forest
    int countTrees() {
        vector<bool> visited(V, false);
        int treeCount = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edges = 0;

                DFS(i, visited, nodes, edges);

                edges /= 2; // each edge counted twice

                if (edges == nodes - 1) {
                    treeCount++;
                }
            }
        }
        return treeCount;
    }
};
int main() {
    Graph g(7);

    // Tree 1
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Tree 2
    g.addEdge(3, 4);

  

    cout << "Number of trees in forest: ";
    cout << g.countTrees();

    return 0;
}