#include <bits/stdc++.h>
using namespace std;
int cycleCount = 0;
void dfs(vector<vector<int>>& graph, vector<bool>& visited,
         int start, int curr, int n, int len) {
    visited[curr] = true;
    // If path length becomes n
    if (len == n) {
        // Check if there is edge back to start
        for (int neighbor : graph[curr]) {
            if (neighbor == start) {
                cycleCount++;
                break;
            }
        }
        visited[curr] = false;
        return;
    }
    // Traverse neighbors
    for (int neighbor : graph[curr]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, start, neighbor, n, len + 1);
        }
    }

    visited[curr] = false;
}
int countCycles(vector<vector<int>>& graph, int V, int n) {
    vector<bool> visited(V, false);
    cycleCount = 0; // reset before use

    for (int i = 0; i < V; i++) {
        dfs(graph, visited, i, i, n, 1);
        visited[i] = true; // avoid duplicate cycles
    }
    return cycleCount / 2;
}
int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };
    int n = 3;
    cout << "Number of cycles of length " << n << " = "
         << countCycles(graph, V, n) << endl;
    return 0;
}