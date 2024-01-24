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
    int N;
    cin >> N;
    cout << matrix[N].size();
    return 0;
}