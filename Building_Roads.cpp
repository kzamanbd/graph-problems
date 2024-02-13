#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group[N];

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        group[i] = 1;
    }
}

int find(int node) {
    if (parent[node] == -1) {
        return node;
    }
    int l = find(parent[node]);
    parent[node] = l;
    return l;
}

void unionBySize(int n1, int n2) {
    int l1 = find(n1);
    int l2 = find(n2);

    if (group[l1] > group[l2]) {
        parent[l2] = l1;
        group[l1] += group[l2];
    }
    else {
        parent[l1] = l2;
        group[l2] += group[l1];
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    initialize(n);
    while (e--) {
        int a, b;
        cin >> a >> b;
        int l1 = find(a);
        int l2 = find(b);
        if (l1 != l2) {
            unionBySize(a, b);
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        res.push_back(find(i));
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() - 1 << endl;
    for (int i = 0; i < res.size() - 1; i++) {
        cout << res[i] << " " << res[i + 1] << endl;
    }

    return 0;
}