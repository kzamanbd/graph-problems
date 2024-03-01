#include <bits/stdc++.h>
using namespace std;
const int N = 55;
bool visited[N];
bool pathVisited[N];
vector<int> grid[N];

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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                grid[i].push_back(j);
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, cycle);
        }
    }

    if (cycle) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}