#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int parent[N];
int group[N];

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}

int dusFind(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int leader = dusFind(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsuUnionBySize(int node1, int node2) {
    int leaderA = dusFind(node1);
    int leaderB = dusFind(node2);

    if (group[leaderA] > group[leaderB]) {
        parent[leaderB] = leaderA;
        group[leaderA] += group[leaderB];
    }
    else {
        parent[leaderA] = leaderB;
        group[leaderB] += group[leaderA];
    }
}


int main() {

    int n;
    cin >> n;
    initialize(n);
    vector<pair<int, int>> exists, create;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        int leaderA = dusFind(u);
        int leaderB = dusFind(v);
        if (leaderA == leaderB) {
            exists.push_back({ u, v });
        }
        else {
            dsuUnionBySize(u, v);
        }
    }

    for (int i = 2; i <= n; i++) {
        int leaderA = dusFind(1);
        int leaderB = dusFind(i);
        if (leaderA != leaderB) {
            create.push_back({ 1, i });
            dsuUnionBySize(1, i);
        }
    }
    cout << exists.size() << endl;
    for (int i = 0; i < exists.size(); i++) {
        cout << exists[i].first << " " << exists[i].second << " " << create[i].first << " " << create[i].second << endl;
    }

    return 0;
}