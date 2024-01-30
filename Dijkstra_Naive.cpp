#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int>> grid[N];
int distances[N];

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        int distances[V];
        for (int i = 0; i < V; i++) {
            distances[i] = INT_MAX;
        }
        queue<pair<int, int>> q;
        q.push({ S, 0 });
        distances[S] = 0;

        while (!q.empty()) {
            pair<int, int> pr = q.front();
            q.pop();
            int node = pr.first;
            int cost = pr.second;
            for (vector<int> child : adj[node]) {
                int cNode = child[0], childCost = child[1];
                int totalCost = cost + childCost;

                if (distances[cNode] > totalCost) {
                    distances[cNode] = totalCost;
                    q.push({ cNode, totalCost });
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < V; i++) {
            res.push_back(distances[i]);
        }
        return res;
    }
};

void dijkstra(int src) {
    queue<pair<int, int>> q;
    q.push({ src, 0 });
    distances[src] = 0;

    while (!q.empty()) {
        auto [node, cost] = q.front();
        q.pop();

        for (auto [cNode, childCost] : grid[node]) {
            int totalCost = cost + childCost;
            if (totalCost < distances[cNode]) {
                // path relax
                distances[cNode] = totalCost;
                q.push({ cNode, totalCost });
            }
        }
    }
}

int main() {

    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({ b, c });
        grid[b].push_back({ a, c });
    }
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
    }
    int src;
    cin >> src;
    dijkstra(src);
    for (int i = 0; i < n; i++) {
        cout << distances[i] << " ";
    }
    return 0;
}