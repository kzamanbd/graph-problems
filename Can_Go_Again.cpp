#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    long long u, v, c;
    Edge(long long u, long long v, long long c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

long long distances[100000];

int main() {

    long long n, e;
    cin >> n >> e;
    vector<Edge> edges;
    while (e--) {
        long long u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    long long MAX_VAL = 1e18;

    for (int i = 1; i <= n; i++) {
        distances[i] = MAX_VAL;
    }
    long long src;
    cin >> src;
    distances[src] = 0;

    for (int i = 1; i < n - 1; i++) {
        for (Edge edge : edges) {
            long long u = edge.u, v = edge.v, c = edge.c;
            if (distances[u] < MAX_VAL && distances[u] + c < distances[v]) {
                distances[v] = distances[u] + c;
            }
        }
    }
    bool isNegativeCycle = false;
    for (int i = 1; i < n - 1; i++) {
        for (Edge edge : edges) {
            long long u = edge.u, v = edge.v, c = edge.c;
            if (distances[u] < MAX_VAL && distances[u] + c < distances[v]) {
                isNegativeCycle = true;
                break;
            }
        }
    }

    if (isNegativeCycle) {
        cout << "Negative Cycle Detected";
    }
    else {
        int testCase;
        cin >> testCase;
        while (testCase--) {
            long long u;
            cin >> u;
            if (distances[u] == MAX_VAL) {
                cout << "Not Possible" << endl;
            }
            else {
                cout << distances[u] << endl;
            }
        }
    }

    return 0;
}