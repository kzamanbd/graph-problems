#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[10];
bool visited[10];

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
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }



    return 0;
}