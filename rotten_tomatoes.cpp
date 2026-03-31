#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int rottenTomatoes(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q; // ((row,col), time)
        int fresh = 0;

        //Initialize queue with all rotten tomatoes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        // Directions (up, down, left, right)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        //BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check valid cell
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // make rotten
                    fresh--;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        // Check if any fresh tomato left
        if (fresh > 0) return -1;

        return time;
    }
};
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution obj;
    int result = obj.rottenTomatoes(grid);

    cout << "Minimum time to rot all tomatoes: " << result;

    return 0;
}