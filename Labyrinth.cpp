#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char grid[N][N];
bool visited[N][N];
pair<int, int> path[N][N];

// Possible moves: up, down, left, right
vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] != '#';
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;

    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto pr = q.front();
        q.pop();

        int si = pr.first, sj = pr.second;

        for (auto move : direction) {
            int i = move.first + si, j = move.second + sj;

            if (isValid(i, j)) {
                visited[i][j] = true;
                q.push({ i, j });
                path[i][j] = { move.first, move.second };
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

    bfs(src);
    if (visited[dest.first][dest.second]) {
        cout << "YES" << endl;
        vector<pair<int, int>> res;
        while (dest.first != src.first || dest.second != src.second) {
            res.push_back(path[dest.first][dest.second]);
            dest.first -= res.back().first;
            dest.second -= res.back().second;
        }
        reverse(res.begin(), res.end());
        string path;
        for (auto p : res) {
            if (make_pair(-1, 0) == p) {
                // up direction
                path.push_back('U');
            }
            else if (make_pair(1, 0) == p) {
                // down direction
                path.push_back('D');
            }
            else if (make_pair(0, -1) == p) {
                // left direction
                path.push_back('L');
            }
            else {
                // right direction
                path.push_back('R');
            }
        }
        cout << path.size() << endl;
        cout << path;
    }
    else {
        cout << "NO";
    }

    return 0;
}