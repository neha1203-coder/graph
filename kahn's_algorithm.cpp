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
    // Add directed edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void kahnTopoSort() {
        vector<int> indegree(V, 0);
         //  Calculate indegree
        for (int i = 0; i < V; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }
        // Push nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        //Process queue
        vector<int> topoOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        //  Check for cycle
        if (topoOrder.size() != V) {
            cout << "Cycle detected! Topological sort not possible." << endl;
            return;
        }
        cout << "Topological Order (Kahn's Algorithm): ";
        for (int x : topoOrder) {
            cout << x << " ";
        }
    }
};
int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.kahnTopoSort();

    return 0;
}