#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
bool visited[N];
int parents[N];

void bfs(int src, bool& cycle) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parents[src] = 0;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        // detect cycle

        for (int child : grid[parent]) {
            if (visited[child] && child != parents[parent]) {
                cycle = true;
            }
            if (!visited[child]) {
                visited[child] = true;
                parents[child] = parent;
                q.push(child);
            }
        }
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        grid[x].push_back(y);
        grid[y].push_back(x);
    }
    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, cycle);
        }
    }
    if (cycle) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}