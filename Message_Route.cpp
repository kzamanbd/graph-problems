#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
bool visited[N];
int parents[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parents[src] = -1;

    while (!q.empty()) {
        int pr = q.front();
        q.pop();

        for (int child : grid[pr]) {
            if (!visited[child]) {
                visited[child] = true;
                parents[child] = pr;
                q.push(child);
            }
        }
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));

    int src = 1, dest = n;
    bfs(src);

    if (visited[dest]) {
        vector<int> res;
        while (dest != -1) {
            res.push_back(dest);
            dest = parents[dest];
        }
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for (int val : res) {
            cout << val << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}