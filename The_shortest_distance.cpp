#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> grid[N];
int visited[N];
int distances[N];

void bfs(int src) {
    queue<int> q;

    q.push(src);
    visited[src] = true;
    distances[src] = 0;
    while (!q.empty()) {
        int pr = q.front();
        q.pop();

        for (int child : grid[pr]) {
            if (!visited[child]) {
                visited[child] = true;
                distances[child] = distances[pr] + 1;
                q.push(child);
            }
        }
    }
}

int main() {

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                grid[i].push_back(j);
            }
        }
    }
    memset(distances, -1, sizeof(distances));
    bfs(x);
    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    return 0;
}