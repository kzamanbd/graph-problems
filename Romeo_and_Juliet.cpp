#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
int level[N];

int bfs(vector<int> grid[], int x, int y) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    level[x] = 0;

    while (!q.empty()) {
        int pr = q.front();
        int lvl = level[pr];
        q.pop();

        if (visited[y]) {
            break;
        }

        for (int child : grid[pr]) {
            if (!visited[child]) {
                visited[child] = true;
                level[child] = lvl + 1;
                q.push(child);
            }
        }
    }
    return level[y];

}

int main() {

    int n, e;
    cin >> n >> e;
    vector<int> grid[n];
    while (e--) {
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    int x, y, k;
    cin >> x >> y >> k;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    int count = bfs(grid, x, y);
    // cout << count;
    if (visited[y] && count <= k * 2) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}