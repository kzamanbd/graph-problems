#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, edge;
    cin >> n >> edge;
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix));

    while (edge--) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}