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
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, count);
            nodes.push_back(count);
        }
    }
    sort(nodes.begin(), nodes.end());
    for (int val : nodes) {
        cout << val << " ";
    }

    return 0;
}