#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void printAllPaths(int source, int destination) {
        vector<bool> visited(vertices, false);
        stack<int> path;
        path.push(source);

        printAllPathsUtil(source, destination, visited, path);
    }

    void printAllPathsUtil(int u, int destination, vector<bool>& visited, stack<int>& path) {
        visited[u] = true;

        if (u == destination) {
            printPath(path);
        }
        else {
            for (int v : adjList[u]) {
                if (!visited[v]) {
                    path.push(v);
                    printAllPathsUtil(v, destination, visited, path);
                    path.pop();
                }
            }
        }

        visited[u] = false;
    }

    void printPath(stack<int>& path) {
        vector<int> temp;
        while (!path.empty()) {
            temp.push_back(path.top());
            path.pop();
        }

        cout << "Path: ";
        for (int i = temp.size() - 1; i >= 0; --i) {
            cout << temp[i];
            if (i != 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int source = 0, destination = 4;
    cout << "All paths from " << source << " to " << destination << " are:\n";
    g.printAllPaths(source, destination);

    return 0;
}
