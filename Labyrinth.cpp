#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char grid[N][N];
bool visited[N][N];
int level[N][N];

// Possible moves: up, down, left, right
vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] != '#';
}

int bfs(pair<int, int> src, pair<bool, string>& res) {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 0;

    while (!q.empty()) {
        auto pr = q.front();
        q.pop();
        int si = pr.first, sj = pr.second;
        int lvl = level[si][sj];

        if (grid[pr.first][pr.second] == 'B') {
            res.first = true;
            // cout << lvl << endl;
            return lvl;
        }

        for (auto move : direction) {
            int i = move.first + pr.first, j = move.second + pr.second;

            if (isValid(i, j)) {
                visited[i][j] = true;
                q.push({ i, j });
                level[i][j] = lvl + 1;
            }
        }
    }
    return -1;
}

int main() {

    cin >> n >> m;
    pair<int, int> src;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                src = { i, j };
            }
        }
    }

    pair<bool, string> res = { false, "" };
    int step = bfs(src, res);
    if (res.first) {
        cout << "YES" << endl;
        cout << step << endl;
    }
    else {
        cout << "NO";
    }

    return 0;
}