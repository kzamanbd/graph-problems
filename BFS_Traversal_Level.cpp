#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[1000];
bool visited[1000];
int level[1000];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty()) {
        int element = q.front();
        q.pop();
        cout << element << " " << level[element] << endl;
        for (int child : matrix[element]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[element] + 1;
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