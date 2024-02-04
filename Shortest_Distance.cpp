#include <bits/stdc++.h>
using namespace std;

int main() {

    long long MAX = 1e18;
    long long n, e;
    cin >> n >> e;
    long long adj[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = MAX;
            if (i == j) {
                adj[i][j] = 0;
            }
        }
    }

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > c) {
            adj[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int src, dest;
        cin >> src >> dest;
        if (adj[src][dest] == MAX) {
            cout << "-1" << endl;
        }
        else {
            cout << adj[src][dest] << endl;
        }
    }


    return 0;
}