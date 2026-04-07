#include <bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, rank;
    // Constructor
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    // Union by Rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
int main() {
    int n = 5; // number of elements
    DSU dsu(n);
    // Perform unions
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    // Check connectivity
    if (dsu.find(0) == dsu.find(2))
        cout << "0 and 2 are in same set\n";
    else
        cout << "0 and 2 are in different sets\n";

    if (dsu.find(0) == dsu.find(4))
        cout << "0 and 4 are in same set\n";
    else
        cout << "0 and 4 are in different sets\n";
    return 0;
}