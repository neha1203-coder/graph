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

    // Print neighbours of a node
    void printNeighbours(int node) {
        if (node < 0 || node >= V) {
            cout << "Invalid node" << endl;
            return;
        }

        cout << "Neighbours of node " << node << ": ";

        for (int neigh : adj[node]) {
            cout << neigh << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    int node = 1;
    g.printNeighbours(node);

    return 0;
}