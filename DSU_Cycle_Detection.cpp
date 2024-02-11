#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int parent[N];
int group[N];

void initalized(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}

int dsuFind(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int l = dsuFind(parent[node]);
    parent[node] = l;
    return l;
}


void dsuUnionBySize(int node1, int node2) {

    int lA = dsuFind(node1);
    int lB = dsuFind(node2);

    if (group[lA] > group[lB]) {
        parent[lB] = lA;
        group[lA] += group[lB];
    }
    else {
        parent[lA] = lB;
        group[lB] += group[lA];
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    initalized(n);

    bool cycle = false;

    while (e--) {
        int a, b;
        cin >> a >> b;
        int lA = dsuFind(a);
        int lB = dsuFind(b);
        if (lA == lB) {
            // cycle detection
            cycle = true;
            cout << a << " " << b << endl;
        }
        else {
            dsuUnionBySize(a, b);
        }
    }

    if (cycle) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}