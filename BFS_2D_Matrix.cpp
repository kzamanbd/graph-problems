#include <bits/stdc++.h>
using namespace std;

char matrix[20][20];
bool visited[20][20];
int distances[20][20];
int n, m;

vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void bfs(int s1, int s2) {

    queue<pair<int, int>> q;
    q.push({ s1, s2 });

    visited[s1][s2] = true;
    distances[s1][s2] = 0;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        string d = "RLUD";
        // cout << p.first << " " << p.second << endl;

        for (auto [i, j] : direction) {
            int si = p.first + i;
            int sj = p.second + j;

            if (isValid(si, sj) && !visited[si][sj]) {
                q.push({ si, sj });
                visited[si][sj] = true;
                distances[si][sj] = distances[p.first][p.second] + 1;
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

    int s1, s2;
    cin >> s1 >> s2;
    memset(visited, false, sizeof(visited));
    memset(distances, -1, sizeof(distances));
    bfs(s1, s2);
    cout << distances[2][3];
    return 0;
}