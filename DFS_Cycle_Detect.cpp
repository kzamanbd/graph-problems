#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
bool visited[N];
int parents[N];

void dfs(int src, bool& cycle) {
    visited[src] = true;
    for (int child : grid[src]) {
        if (visited[child] && child != parents[src]) {
            cycle = true;
        }
        if (!visited[child]) {
            parents[child] = src;
            dfs(child, cycle);
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