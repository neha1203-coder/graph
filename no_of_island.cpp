#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n, m;
    // DFS function
    void dfs(int i, int j, vector<vector<char>> &grid) {
        // Boundary check + water check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        grid[i][j] = '0'; // mark visited
        // 4 directions
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid); // visit whole island
                }
            }
        }

        return count;
    }
};
int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0'},
        {'1','0','0','1'},
        {'0','0','1','1'},
        {'0','0','0','0'}
    };

    Solution obj;
    cout << "Number of Islands: " << obj.numIslands(grid);

    return 0;
}