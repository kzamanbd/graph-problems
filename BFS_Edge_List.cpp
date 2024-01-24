#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges;

    while (e--) {
        int a, b;
        cin >> a >> b;
        edges.push_back({ a, b });
    }

    for (auto [x, y] : edges) {
        cout << x << " " << y << endl;
    }

    return 0;
}