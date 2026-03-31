#include <iostream>
#include <queue>
#include <set>
using namespace std;
// State = (jug1, jug2)
bool waterJug(int m, int n, int d) {
    set<pair<int,int>> visited;
    queue<pair<int,int>> q;

    q.push({0, 0});

    while (!q.empty()) {
        auto state = q.front();
        q.pop();

        int x = state.first;
        int y = state.second;

        // If target found
        if (x == d || y == d || x + y == d)
            return true;

        if (visited.count({x, y}))
            continue;

        visited.insert({x, y});

        // 1. Fill Jug1
        q.push({m, y});

        // 2. Fill Jug2
        q.push({x, n});

        // 3. Empty Jug1
        q.push({0, y});

        // 4. Empty Jug2
        q.push({x, 0});

        // 5. Pour Jug1 → Jug2
        int pour1 = min(x, n - y);
        q.push({x - pour1, y + pour1});

        // 6. Pour Jug2 → Jug1
        int pour2 = min(y, m - x);
        q.push({x + pour2, y - pour2});
    }

    return false;
}
int main() {
    int m = 4, n = 3, d = 2;

    if (waterJug(m, n, d))
        cout << "Possible to measure " << d << " liters";
    else
        cout << "Not possible";

    return 0;
}