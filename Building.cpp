#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long parent[N];
long long group[N];
void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}
int dsuFind(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int leader = dsuFind(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsuUnionBySize(int n1, int n2) {
    int l1 = dsuFind(n1);
    int l2 = dsuFind(n2);

    if (group[l1] > group[l2]) {
        parent[l2] = l1;
        group[l1] += group[l2];
    }
    else {
        parent[l1] = l2;
        group[l2] += group[l1];
    }
}

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool compare(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int main() {

    int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    initialize(n);
    sort(edges.begin(), edges.end(), compare);


    long long totalCost = 0;
    int nodeCount = 0;
    for (auto edge : edges) {
        int l1 = dsuFind(edge.u);
        int l2 = dsuFind(edge.v);

        if (l1 == l2) {
            continue;
        }
        else {
            dsuUnionBySize(edge.u, edge.v);
            totalCost += edge.w;
            nodeCount++;
        }
    }

    if (nodeCount == n - 1) {

        cout << totalCost;
    }
    else {
        cout << "-1";
    }


    return 0;
}