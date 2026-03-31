#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<int>& board) {
        int N = board.size();

        vector<bool> visited(N, false);
        queue<pair<int,int>> q; // {cell, moves}

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            int cell = q.front().first;
            int moves = q.front().second;
            q.pop();

            // If reached last cell
            if (cell == N - 1) return moves;

            // Dice moves (1 to 6)
            for (int dice = 1; dice <= 6; dice++) {
                int next = cell + dice;

                if (next < N && !visited[next]) {
                    visited[next] = true;

                    // If snake or ladder exists
                    if (board[next] != -1)
                        next = board[next];

                    q.push({next, moves + 1});
                }
            }
        }

        return -1; // not reachable
    }
};

int main() {
    // -1 means no snake/ladder
    vector<int> board = {
        -1, -1, -1, -1, -1, -1,
        -1, -1,  21, -1, -1, -1,
        -1, -1, -1, -1, -1, -1,
        -1,  7, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1
    };

    Solution obj;
    int result = obj.snakesAndLadders(board);

    cout << "Minimum moves to reach end: " << result;

    return 0;
}