#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[1000];
bool visited[1000];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int element = q.front();
        q.pop();
        cout << element << " ";
        for (int child : matrix[element]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }

    }
}

int main() {

    int n, edge;
    cin >> n >> edge;

    while (edge--) {
        int x, y;
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    bfs(src);

    return 0;
}