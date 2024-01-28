#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix));
    while (e--) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
    }

    int query;
    cin >> query;

    while (query--) {
        int a, b;
        cin >> a >> b;
        if (matrix[a][b] == 1 || a == b) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;

    }
    return 0;
}