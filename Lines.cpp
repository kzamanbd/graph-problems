#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n;
char grid[N][N];
bool visited[N][N];
pair<int, int> path[N][N];

// up, down, left, right
vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && !visited[i][j] && grid[i][j] != 'O';
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto pr = q.front();
        q.pop();

        for (auto move : direction) {
            int i = pr.first + move.first, j = pr.second + move.second;
            if (isValid(i, j)) {
                visited[i][j] = true;
                path[i][j] = { move.first, move.second };
                q.push({ i,j });
            }
        }
    }
}

int main() {

    cin >> n;
    pair<int, int> src, dest;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '@') {
                src = { i,j };
            }
            if (grid[i][j] == 'X') {
                dest = { i,j };
            }
        }
    }
    memset(visited, false, sizeof(visited));
    bfs(src);

    if (visited[dest.first][dest.second]) {
        cout << "Y" << endl;
        vector<pair<int, int>> res;
        while (dest.first != src.first || dest.second != src.second) {
            if (grid[dest.first][dest.second] != '@') {
                grid[dest.first][dest.second] = '+';
            }
            res.push_back(path[dest.first][dest.second]);
            dest.first -= res.back().first;
            dest.second -= res.back().second;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "N";
    }

    return 0;
}