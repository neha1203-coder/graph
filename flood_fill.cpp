#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n, m;
    void dfs(int r, int c, vector<vector<int>> &image, int oldColor, int newColor) {
        // Boundary check + color check
        if (r < 0 || c < 0 || r >= n || c >= m || image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        // 4 directions
        dfs(r+1, c, image, oldColor, newColor);
        dfs(r-1, c, image, oldColor, newColor);
        dfs(r, c+1, image, oldColor, newColor);
        dfs(r, c-1, image, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();

        int oldColor = image[sr][sc];

        // Important check (avoid infinite recursion)
        if (oldColor == newColor) return image;

        dfs(sr, sc, image, oldColor, newColor);

        return image;
    }
};
int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, newColor = 2;

    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}