#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];
int distanceOfSrc[101];
int distanceOfDest[101];

void bfs(int src, bool isSrc) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    if (isSrc) {
        distanceOfSrc[src] = 0;
    }
    else {
        distanceOfDest[src] = 0;
    }

    while (!q.empty()) {
        int pr = q.front();
        q.pop();

        for (int child : adj[pr]) {
            if (!visited[child]) {
                visited[child] = true;
                if (isSrc) {
                    distanceOfSrc[child] = distanceOfSrc[pr] + 1;
                }
                else {
                    distanceOfDest[child] = distanceOfDest[pr] + 1;
                }
                q.push(child);
            }
        }
    }
}

int main() {

    int tc;
    cin >> tc;
    int output = 1;
    while (tc--) {
        int n, e;
        cin >> n >> e;
        while (e--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int src, dest;
        cin >> src >> dest;
        memset(visited, false, sizeof(visited));
        memset(distanceOfSrc, -1, sizeof(distanceOfSrc));
        bfs(src, true);

        memset(visited, false, sizeof(visited));
        memset(distanceOfDest, -1, sizeof(distanceOfDest));
        bfs(dest, false);

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, distanceOfSrc[i] + distanceOfDest[i]);
            adj[i].clear();
        }


        cout << "Case " << output++ << ": " << mx << endl;
    }
    return 0;
}