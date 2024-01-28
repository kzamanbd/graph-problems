#include <bits/stdc++.h>
using namespace std;

int n, m;
int matrix[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> direction = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && matrix[i][j] != -1;
}

void bfs(int sr, int sc) {

    queue<pair<int, int>> q;
    q.push({ sr, sc });

    visited[sr][sc] = true;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto [i, j] : direction) {
            int si = p.first + i;
            int sj = p.second + j;

            if (isValid(si, sj)) {
                q.push({ si, sj });
                visited[si][sj] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    pair<int, int> src, dest;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                matrix[i][j] = -1;
            }
            if (s[j] == 'A') {
                src = { i,j };
            }
            if (s[j] == 'B') {
                dest = { i,j };
            }
        }
    }

    bfs(src.first, src.second);

    if (visited[dest.first][dest.second]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}