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
    // Add directed edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    // Calculate sum of dependencies
    int sumDependencies() {
        int sum = 0;

        for (int i = 0; i < V; i++) {
            sum += adj[i].size(); // number of outgoing edges
        }

        return sum;
    }
};
int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Sum of dependencies: " << g.sumDependencies();

    return 0;
}