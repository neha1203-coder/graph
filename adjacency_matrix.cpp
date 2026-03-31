#include <iostream>
using namespace std;

class Graph {
    int V;
    int **adj;
public:
    Graph(int V) {
        this->V = V;

        // Allocate matrix
        adj = new int*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V];
        }
        // Initialize with 0
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }
    // Add edge (undirected)
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Print matrix
    void printMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.printMatrix();

    return 0;
}