#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> grid[N];
int level[N];
bool visited[N];
int parents[N];

void bfs(int src, int dest) {
    queue<int> q;

    q.push(src);
    level[src] = 0;
    visited[src] = true;
    parents[src] = -1;

    while (!q.empty()) {
        int element = q.front();
        q.pop();

        for (int child : grid[element]) {
            if (!visited[child]) {
                visited[child] = true;
                level[child] = level[element] + 1;
                parents[child] = element;
                q.push(child);
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
        grid[x].push_back(y);
    }

    int src = 1, dest = n;
    memset(visited, false, sizeof(visited));
    bfs(src, dest);

    vector<int> res;

    while (dest != -1) {
        res.push_back(dest);
        dest = parents[dest];
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}