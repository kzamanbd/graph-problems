#include <bits/stdc++.h>
using namespace std;

bool visited[1000];
int level[1000];

void dfs(vector<int> edges[], int src, int dest) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    int distance = -1;

    while (!q.empty()) {
        int el = q.front();
        q.pop();
        int lvl = level[el];

        if (el == dest) {
            distance = lvl;
            break;
        }
        for (auto child : edges[el]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = lvl + 1;
            }
        }
    }
    cout << distance << endl;

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

    int query;
    cin >> query;
    while (query--) {
        int src, dest;
        cin >> src >> dest;
        memset(visited, false, sizeof(visited));
        memset(level, 0, sizeof(level));
        dfs(matrix, src, dest);
    }

    return 0;
}