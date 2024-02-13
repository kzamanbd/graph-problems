#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char grid[N][N];
bool visited[N][N];

// Possible moves: up, down, left, right
vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] != '#';
}

bool flag = false;

void bfs(pair<int, int> src, pair<int, int> dest, pair<bool, string>& res) {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto pr = q.front();
        q.pop();

        if (visited[dest.first][dest.second]) {
            res.first = true;
            return;
        }

        for (auto move : direction) {
            int i = move.first + pr.first, j = move.second + pr.second;

            if (isValid(i, j)) {
                visited[i][j] = true;
                q.push({ i, j });
                res.second += (move == make_pair(-1, 0) ? "U" : (move == make_pair(1, 0) ? "D" : (move == make_pair(0, -1) ? "L" : "R")));
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
            if (grid[i][j] == 'A') {
                src = { i, j };
            }
            if (grid[i][j] == 'B') {
                dest = { i, j };
            }
        }
    }

    pair<bool, string> res = { false, "" };
    bfs(src, dest, res);
    if (res.first) {
        cout << "YES" << endl;
        cout << res.second.size() << endl;
        cout << res.second;
    }
    else {
        cout << "NO";
    }

    return 0;
}