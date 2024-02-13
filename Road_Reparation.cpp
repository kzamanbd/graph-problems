#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long parent[N];
long long group[N];


void initialize(long long n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}

// find dsu
long long dsuFind(long long node) {
    if (parent[node] == -1) {
        return node;
    }
    long long leader = dsuFind(parent[node]);
    parent[node] = leader;
    return leader;
}

// dsu union find by group size
void dsuUnionBySize(long long node1, long long node2) {
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
    long long u, v, w;
    Edge(long long u, long long v, long long w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool compare(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

bool visited[N];
vector<int> grid[N];

void dfs(int src) {
    visited[src] = true;
    for (int child : grid[src]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

bool countConnectedComponents(vector<int> grid[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
        if (count > 2) {
            return true;
        }
    }
    // cout << count;
    return false;
}

int main() {

    long long n, e;
    cin >> n >> e;
    initialize(n);
    vector<Edge> edgeList;

    while (e--) {
        long long u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    bool isNotConnected = countConnectedComponents(grid, n);
    if (isNotConnected) {
        cout << "IMPOSSIBLE";
    }
    else {
        sort(edgeList.begin(), edgeList.end(), compare);
        long long totalCost = 0;
        for (auto e : edgeList) {

            long long leaderU = dsuFind(e.u);
            long long leaderV = dsuFind(e.v);
            if (leaderU == leaderV) {
                // cout << leaderU << " " << leaderV << endl;
                continue;
            }
            else {
                dsuUnionBySize(e.u, e.v);
                totalCost += e.w;
            }
        }
        cout << totalCost;
    }


    return 0;
}