#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[1000];
bool visited[1000];
int level[1000];
int parents[1000];

void bfs(int src, int dest) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    parents[src] = -1;

    while (!q.empty()) {
        int element = q.front();
        q.pop();
        for (int child : matrix[element]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[element] + 1;
                parents[child] = element;
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

    int src, dest;
    cin >> src >> dest;
    memset(visited, false, sizeof(visited));
    bfs(src, dest);

    int x = dest;
    while (x != -1) {
        cout << x << "->";
        x = parents[x];
    }


    return 0;
}