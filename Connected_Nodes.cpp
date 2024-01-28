#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, edge;
    cin >> n >> edge;
    vector<int> matrix[n + 1];

    while (edge--) {
        int x, y;
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }

    int query;
    cin >> query;
    while (query--) {
        int x;
        cin >> x;
        vector<int> res;
        for (auto val : matrix[x]) {
            res.push_back(val);
        }
        sort(res.begin(), res.end(), greater<>());

        if (res.size() == 0) {
            cout << "-1";
        }
        else {
            for (auto val : res) {
                cout << val << " ";
            }
        }
        cout << endl;
    }
    return 0;
}