#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char grid[N][N];
bool visited[N][N];
int n, m;


vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

void dfs(int sr, int sc, int& count) {
    count++;
    visited[sr][sc] = true;

    for (auto p : direction) {
        int i = sr + p.first;
        int j = sc + p.second;
        if (isValid(i, j) && !visited[i][j]) {
            dfs(i, j, count);
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
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                int count = 0;
                dfs(i, j, count);
                mn = min(count, mn);
            }
        }
    }

    if (mn == INT_MAX) {
        cout << "-1";
        return 0;
    }

    cout << mn;

    return 0;
}