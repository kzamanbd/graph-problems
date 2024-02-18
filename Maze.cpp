#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
char grid[N][N];
bool visited[N][N];
pair<int, int> path[N][N];

// right, left, up, and down.
vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#';
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;

    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        for (auto move : direction) {
            int ci = front.first + move.first, cj = front.second + move.second;

            if (isValid(ci, cj) && !visited[ci][cj]) {
                visited[ci][cj] = true;
                q.push({ ci, cj });
                path[ci][cj] = { move.first, move.second };
            }
        }
    }
}

int main() {

    cin >> n >> m;
    pair<int, int> src, dest;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                src = { i,j };
            }
            if (grid[i][j] == 'D') {
                dest = { i,j };
            }
        }
    }
    bfs(src);
    if (visited[dest.first][dest.second]) {
        vector<pair<int, int>> res;
        while (dest.first != src.first || dest.second != src.second) {
            res.push_back(path[dest.first][dest.second]);
            // cout << dest.first << " " << dest.second << endl;
            dest.first -= res.back().first;
            dest.second -= res.back().second;

            if (grid[dest.first][dest.second] == '.') {
                grid[dest.first][dest.second] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}