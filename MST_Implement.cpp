#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int parent[N];
int group[N];


void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}

// find dsu
int dsuFind(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int leader = dsuFind(parent[node]);
    parent[node] = leader;
    return leader;
}

// dsu union find by group size
void dsuUnionBySize(int node1, int node2) {
    int leaderA = dsuFind(node1);
    int leaderB = dsuFind(node2);

    if (group[leaderA] > group[leaderB]) {
        parent[leaderB] = leaderA;
        group[leaderA] += group[leaderB];
    }
    else {
        parent[leaderA] = leaderB;
        group[leaderB] += group[leaderA];
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
    initialize(n);
    vector<Edge> edgeList;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), compare);

    int totalCost = 0;
    for (auto e : edgeList) {
        // cout << e.u << " " << e.v << " " << e.w << endl;

        int leaderU = dsuFind(e.u);
        int leaderV = dsuFind(e.v);
        if (leaderU == leaderV) {
            cout << leaderU << " " << leaderV << endl;
            continue;
        }
        else {
            dsuUnionBySize(e.u, e.v);
            totalCost += e.w;
        }
    }
    cout << totalCost;
    return 0;
}