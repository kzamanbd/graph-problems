#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

char matrix[20][20];
bool visited[20][20];
int n, m;

vector<pi> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void dfs(int s1, int s2) {
    cout << s1 << " " << s2 << endl;
    visited[s1][s2] = true;
    for (auto p : direction) {
        int i = s1 + p.first;
        int j = s2 + p.second;
        if (isValid(i, j) && !visited[i][j]) {
            dfs(i, j);
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

    int s1, s2;
    cin >> s1 >> s2;
    memset(visited, false, sizeof(visited));
    dfs(s1, s2);
    return 0;
}