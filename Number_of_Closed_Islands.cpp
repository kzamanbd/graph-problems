/*
[0,0,1,1,0,1,0,0,1,0]
[1,1,0,1,1,0,1,1,1,0]
[1,0,1,1,1,0,0,1,1,0]
[0,1,1,0,0,0,0,1,0,1]
[0,0,0,0,0,0,1,1,1,0]
[0,1,0,1,0,1,0,1,1,1]
[1,0,1,0,1,1,0,0,0,1]
[1,1,1,1,1,1,0,0,0,0]
[1,1,1,0,0,1,0,1,0,1]
[1,1,1,0,1,1,0,1,1,0]

test case 30

[1,1,0,1,1,1,1,1,1,1]
[0,0,1,0,0,1,0,1,1,1]
[1,0,1,0,0,0,1,0,1,0]
[1,1,1,1,1,0,0,1,0,0]
[1,0,1,0,1,1,1,1,1,0]
[0,0,0,0,1,1,0,0,0,0]
[1,0,1,0,0,0,0,1,1,0]
[1,1,0,0,1,1,0,0,0,0]
[0,0,0,1,1,0,1,1,1,0]
[1,1,0,1,0,1,0,0,1,0]

1 1
1 3
1 6
2 7
4 3
8 5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    bool visited[101][101];
    vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };
    bool isValid(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    bool isLastZero(int i, int j, vector<vector<int>>& grid) {
        if ((i == 0 && grid[i][j] == 0) || (i == n - 1 && grid[i][j] == 0) || (j == 0 && grid[i][j] == 0) || (j == m - 1 && grid[i][j] == 0)) {
            return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid, pair<int, int> src) {
        queue<pair<int, int>> q;

        q.push(src);
        visited[src.first][src.second] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (isLastZero(x, y, grid)) {
                return false;
            }

            for (auto d : direction) {
                int i = x + d.first;
                int j = y + d.second;

                if (isValid(i, j) && !visited[i][j] && grid[i][j] == 0) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
            }
        }
        return true;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int count = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(grid, { i, j })) {
                        cout << i << " " << j << endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.closedIsland(grid);
    return 0;
}