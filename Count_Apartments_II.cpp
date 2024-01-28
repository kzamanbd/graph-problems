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

void bfs(pair<int, int> src, vector<int>& apartments) {
    queue<pair<int, int>> q;

    q.push(src);
    visited[src.first][src.second] = true;
    int count = 1;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto d : direction) {
            int i = p.first + d.first;
            int j = p.second + d.second;

            if (isValid(i, j) && !visited[i][j] && matrix[i][j] == '.') {
                q.push({ i, j });
                visited[i][j] = true;
                count++;
            }
        }
    }
    apartments.push_back(count);
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> apartments;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                bfs({ i, j }, apartments);
            }
        }
    }

    if (apartments.empty()) {
        cout << "0";
    }
    else {
        sort(apartments.begin(), apartments.end());

        for (int val : apartments) {
            cout << val << " ";
        }
    }
    return 0;
}