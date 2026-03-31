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
    // Add edge (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // BFS to check bipartite
    bool BFS(int start, vector<int> &color) {
        queue<int> q;

        q.push(start);
        color[start] = 0; // first color

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                // If not colored
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - color[node]; // opposite color
                    q.push(neighbour);
                }
                // If same color --- not bipartite
                else if (color[neighbour] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check whole graph
    bool isBipartite() {
        vector<int> color(V, -1); // -1 = uncolored

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!BFS(i, color))
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if (g.isBipartite())
        cout << "Graph is Bipartite";
    else
        cout << "Graph is NOT Bipartite";

    return 0;
}