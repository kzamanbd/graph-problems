#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int distances[100000];

int main() {

    int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    while (e--) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    int MAX_VAL = 30000;

    for (int i = 1; i <= n; i++) {
        distances[i] = MAX_VAL;
    }
    int src = 1;
    distances[src] = 0;

    for (int i = 1; i < n - 1; i++) {
        for (Edge edge : edges) {
            int u = edge.u, v = edge.v, c = edge.c;
            if (distances[u] < MAX_VAL && distances[u] + c < distances[v]) {
                distances[v] = distances[u] + c;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }

    return 0;
}