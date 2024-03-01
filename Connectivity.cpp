#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grid[N];
bool visited[N];

void dfs(int src) {
    visited[src] = true;
    for (int child : grid[src]) {
        if (!visited[child]) {
            dfs(child);
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
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    if (count == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}