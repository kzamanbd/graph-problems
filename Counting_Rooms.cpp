#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
bool visited[N][N];

vector<pair<int, int>> moves = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] == '.';
}

void dfs(int sr, int sc) {
    visited[sr][sc] = true;

    for (auto [x, y] : moves) {
        int i = sr + x, j = sc + y;
        if (isValid(i, j)) {
            dfs(i, j);
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int component = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isValid(i, j)) {
                component++;
                dfs(i, j);
            }
        }
    }
    cout << component;
    return 0;
}