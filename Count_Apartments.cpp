#include <bits/stdc++.h>
using namespace std;

int n, m;
char matrix[1000][1000];
bool visited[1000][1000] = { false };
vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;

    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto d : direction) {
            int i = p.first + d.first;
            int j = p.second + d.second;

            if (isValid(i, j) && !visited[i][j] && matrix[i][j] == '.') {
                q.push({ i, j });
                visited[i][j] = true;
            }
        }
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                count++;
                bfs({ i, j });
            }
        }
    }

    cout << count;

    return 0;
}