//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int parent[10000];
    int group[10000];

    void initialize(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            group[i] = 1;
        }
    }

    int dsuFind(int node) {
        if (parent[node] == -1) {
            return node;
        }
        int leader = dsuFind(parent[node]);
        parent[node] = leader;
        return leader;
    }
    void unionBySize(int node1, int node2) {
        int leaderA = dsuFind(node1);
        int leaderB = dsuFind(node2);

        if (group[leaderA] > group[leaderB]) {
            parent[leaderB] = leaderA;
            group[leaderA] += group[leaderB];
        }
        else {
            parent[leaderA] = leaderB;
            group[leaderB] += group[leaderA];
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int>adj[]) {
        // Code here
        initialize(V);
        int flag = 0;
        for (int i = 0; i < V; i++) {
            int a = adj[i][0];
            int b = adj[i][1];
            int leaderA = dsuFind(a);
            int leaderB = dsuFind(b);
            if (leaderA == leaderB) {
                flag = 1;
            }
            else {
                unionBySize(a, b);
            }
        }
        return flag;

    }
};

//{ Driver Code Starts.
int main() {
    int V, E;
    cin >> V >> E;
    vector<int>adj[1000];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    int ans = obj.detectCycle(V, adj);
    cout << ans << "\n";
    return 0;
}
// } Driver Code Ends