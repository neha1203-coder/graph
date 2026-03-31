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
    // Find maximum weight node
    int maxWeightNode() {
        int maxSum = -1;
        int resultNode = -1;

        for (int i = 0; i < V; i++) {
            int sum = 0;

            for (int neigh : adj[i]) {
                sum += neigh; // sum of neighbour node values
            }

            if (sum > maxSum) {
                maxSum = sum;
                resultNode = i;
            }
        }

        return resultNode;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    int node = g.maxWeightNode();

    cout << "Maximum Weight Node: " << node;

    return 0;
}