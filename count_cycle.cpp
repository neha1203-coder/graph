#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    int count;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        count = 0;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int start, int curr, vector<bool> &visited, int length, int n) {
        visited[curr] = true;
        // If cycle length reached
        if (length == n) {
            visited[curr] = false;
            // Check if there is edge back to start
            for (int neigh : adj[curr]) {
                if (neigh == start) {
                    count++;
                    break;
                }
            }
            return;
        }
        for (int neigh : adj[curr]) {
            if (!visited[neigh]) {
                dfs(start, neigh, visited, length + 1, n);
            }
        }
        visited[curr] = false; // backtrack
    }
    int countCycles(int n) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            dfs(i, i, visited, 1, n);
            visited[i] = true; // avoid duplicate cycles
        }
        return count / 2;   // Each cycle counted twice
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // triangle

    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1); // another triangle

    int n = 3; // cycle length

    cout << "Number of cycles of length " << n << " = "
         << g.countCycles(n);

    return 0;
}