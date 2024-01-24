#include <bits/stdc++.h>
using namespace std;

bool visited[1000];
int level[1000];

void dfs(vector<int> edges[], int src, int lvl, vector<int>& L) {
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visited[src] = true;

    while (!q.empty()) {
        int el = q.front();
        q.pop();

        if (level[el] == lvl) {
            L.push_back(el);
        }

        for (auto child : edges[el]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[el] + 1;
            }
        }
    }
}

int main() {

    int n, edge;
    cin >> n >> edge;

    vector<int> matrix[1000];

    while (edge--) {
        int x, y;
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    int lvl;
    cin >> lvl;
    memset(visited, false, sizeof(visited));
    memset(level, 0, sizeof(level));
    int src = 0;
    vector<int> L;
    dfs(matrix, src, lvl, L);

    reverse(L.begin(), L.end());
    for (auto val : L) {
        cout << val << " ";
    }

    return 0;
}