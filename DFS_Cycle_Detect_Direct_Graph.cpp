#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
bool visited[N];
bool pathVisited[N];

void dfs(int src, bool& cycle) {
    visited[src] = true;
    pathVisited[src] = true;
    for (int child : grid[src]) {
        if (pathVisited[child]) {
            cycle = true;
        }
        if (!visited[child]) {
            dfs(child, cycle);
        }
    }
    pathVisited[src] = false;
}

int main() {

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        grid[x].push_back(y);
    }
    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, cycle);
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