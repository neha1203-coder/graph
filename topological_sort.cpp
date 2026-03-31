#include <iostream>
#include <vector>
#include <stack>
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
    void DFS(int node, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                DFS(neigh, visited, st);
            }
        }

        st.push(node); // push after visiting all neighbours
    }

    void topoSort() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, visited, st);
            }
        }

        cout << "Topological Order (DFS): ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
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

    g.topoSort();

    return 0;
}