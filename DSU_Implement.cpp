#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int parent[N];
int groupSize[N];
int level[N];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        groupSize[i] = 1;
        level[i] = 0;
    }
    // parent[1] = 3;
    // parent[2] = 1;
}

int dsuFind(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int leader = dsuFind(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsuUnion(int node1, int node2) {
    int leaderA = dsuFind(node1);
    int leaderB = dsuFind(node2);
    parent[leaderA] = leaderB;
}

void dsuUnionBySize(int node1, int node2) {
    int leaderA = dsuFind(node1);
    int leaderB = dsuFind(node2);

    if (groupSize[leaderA] > groupSize[leaderB]) {
        parent[leaderB] = leaderA;
        groupSize[leaderA] += groupSize[leaderB];
    }
    else {
        parent[leaderA] = leaderB;
        groupSize[leaderB] += groupSize[leaderA];
    }
}

void dsuUnionByLevel(int node1, int node2) {
    int leaderA = dsuFind(node1);
    int leaderB = dsuFind(node2);
    if (level[leaderA] > level[leaderB]) {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA]) {
        parent[leaderA] = leaderB;
    }
    else {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}


int main() {

    initialize(78);
    dsuUnionByLevel(1, 2);
    dsuUnionByLevel(2, 3);
    dsuUnionByLevel(4, 5);
    dsuUnionByLevel(5, 6);
    dsuUnionByLevel(1, 4);
    cout << dsuFind(1) << endl;
    cout << dsuFind(4) << endl;

    return 0;
}