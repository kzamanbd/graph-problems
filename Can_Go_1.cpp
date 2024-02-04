#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<pair<long long, long long>> grid[N];
long long distances[N];

class Compare {
public:
    bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
        return a.second > b.second;
    }
};

void dijkstra(long long src) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Compare> pq;
    pq.push({ src, 0 });
    distances[src] = 0;

    while (!pq.empty()) {
        auto pr = pq.top();
        long long node = pr.first, cost = pr.second;
        pq.pop();

        for (auto child : grid[node]) {
            long long cNode = child.first;
            long long totalCost = cost + child.second;
            if (distances[cNode] > totalCost) {
                pq.push({ cNode, totalCost });
                distances[cNode] = totalCost;
            }
        }
    }
}

int main() {

    long long n, e;
    cin >> n >> e;
    while (e--) {
        long long a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({ b, c });
    }

    for (int i = 1; i <= n; i++) {
        distances[i] = 1e18;
    }

    long long src;
    cin >> src;
    dijkstra(src);

    long long testCase;
    cin >> testCase;
    while (testCase--) {
        long long dest, cost;
        cin >> dest >> cost;
        if (cost >= distances[dest]) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}