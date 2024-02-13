#include <bits/stdc++.h>
#define pi pair<long long, long long>
using namespace std;

const int N = 1e5 + 5;
long long distances[N];
long long parents[N];

class Compare {
public:
    bool operator()(pi a, pi b) {
        return a.second > b.second;
    }
};


void dijkstra(vector<pi> grid[]) {
    priority_queue<pi, vector<pi>, Compare> pq;

    int src = 1;
    pq.push({ src, 0 });
    distances[src] = 0;

    while (!pq.empty()) {
        auto [node, cost] = pq.top();
        pq.pop();

        for (auto [cNode, childCost] : grid[node]) {
            long long totalCost = cost + childCost;
            if (distances[cNode] > totalCost) {
                pq.push({ cNode, totalCost });
                distances[cNode] = totalCost;
                parents[cNode] = node;
            }
        }
    }
    cout << endl;
}

int main() {

    long long n, e;
    cin >> n >> e;
    vector<pi> grid[n + 1];

    while (e--) {
        long long u, v, w;
        cin >> u >> v >> w;
        grid[u].push_back({ v, w });
        grid[v].push_back({ u, w });
    }

    for (int i = 1; i <= n; i++) {
        distances[i] = 1e18;
        parents[i] = -1;
    }

    dijkstra(grid);

    if (distances[n] == 1e18) {
        cout << "-1";
    }
    else {

        int x = n;

        vector<int> res;
        while (x != -1) {
            res.push_back(x);
            x = parents[x];
        }
        reverse(res.begin(), res.end());

        for (int val : res) {
            cout << val << " ";
        }
    }

    return 0;
}