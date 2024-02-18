#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
bool visited[N];
int parent[N];
int distances[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    distances[src] = 0;

    while (!q.empty()) {
        int pr = q.front();
        q.pop();

        for (int child : grid[pr]) {
            if (!visited[child]) {
                visited[child] = true;
                distances[child] = distances[pr] + 1;
                parent[child] = pr;
                q.push(child);
            }
        }
    }
}

int main() {

    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    memset(distances, -1, sizeof(distances));
    bfs(src);
    if (!visited[dest]) {
        cout << "-1";
    }
    else {
        cout << distances[dest] << endl;
        // path printing 
        vector<int> path;
        while (dest != -1) {
            path.push_back(dest);
            dest = parent[dest];
        }
        reverse(path.begin(), path.end());
        for (int val : path) {
            cout << val << " ";
        }
    }
    return 0;
}