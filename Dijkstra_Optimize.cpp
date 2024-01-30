#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int>> grid[N];
int distances[N];

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({ src, 0 });
    distances[src] = 0;

    while (!pq.empty()) {
        auto [node, cost] = pq.top();
        pq.pop();

        for (auto [cNode, childCost] : grid[node]) {
            int totalCost = cost + childCost;
            if (distances[cNode] > totalCost) {
                pq.push({ cNode, totalCost });
                distances[cNode] = totalCost;
            }
        }
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({ b, c });
        grid[b].push_back({ a, c });
    }
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
    }
    int src;
    cin >> src;
    dijkstra(src);
    for (int i = 0; i < n; i++) {
        cout << distances[i] << " ";
    }
    return 0;
}