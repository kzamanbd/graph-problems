#include <bits/stdc++.h>
using namespace std;

const int N = 100;

char matrix[N][N];
bool visited[N][N];
int distances[N][N];
int n, m;

vector<pair<int, int>> direction = { { 1, 2 }, {1, -2}, {-1, 2}, {-1, -2},{ 2, 1 }, {-2, 1}, {2, -1}, {-2, -1} };


bool isValid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src, pair<int, int> dest) {

    queue<pair<int, int>> q;
    q.push(src);

    visited[src.first][src.second] = true;
    distances[src.first][src.second] = 0;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto child : direction) {
            int i = p.first + child.first;
            int j = p.second + child.second;

            if (isValid(i, j) && !visited[i][j]) {
                q.push({ i, j });
                visited[i][j] = true;
                distances[i][j] = distances[p.first][p.second] + 1;
            }
        }
    }
}

int main() {

    int testCase;
    cin >> testCase;
    while (testCase--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = '.';
            }
        }

        pair<int, int> src, dest;
        cin >> src.first >> src.second;
        cin >> dest.first >> dest.second;

        memset(visited, false, sizeof(visited));
        memset(distances, -1, sizeof(distances));
        bfs(src, dest);
        cout << distances[dest.first][dest.second] << endl;
    }


    return 0;
}