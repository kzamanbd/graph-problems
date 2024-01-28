#include <bits/stdc++.h>
using namespace std;

vector<int> grid[100];
bool visited[100];

void dfs(int src, int& count) {
    count++;
    visited[src] = true;
    for (int child : grid[src]) {
        if (!visited[child]) {
            dfs(child, count);
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
    int src;
    cin >> src;
    int count = 0;
    dfs(src, count);
    cout << count;
    return 0;
}