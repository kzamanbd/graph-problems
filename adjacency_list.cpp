#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, edge;
    cin >> n >> edge;
    vector<int> matrix[n];

    while (edge--) {
        int x, y;
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    for (int i = 0; i < n;i++) {
        cout << i << ": ";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}