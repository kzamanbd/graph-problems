#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[100];
bool visited[100];

void dfs(int src) {
    cout << src << endl;
    visited[src] = true;

    for (auto val : matrix[src]) {
        if (!visited[val]) {
            dfs(val);
        }
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    while (e--) {
        int x, y;
        cin >> x >> y;
        matrix[y].push_back(x);
        matrix[x].push_back(y);
    }
    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    dfs(src);
    return 0;
}