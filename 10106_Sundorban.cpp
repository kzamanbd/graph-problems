#include <bits/stdc++.h>
using namespace std;
const int N = 30;

int n;
char grid[N][N];
bool visited[N][N];
int level[N][N];

// Possible moves: up, down, left, right
vector<pair<int, int> > direction;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && !visited[i][j] && grid[i][j] != 'T';
}

void bfs(pair<int, int> src) {
    queue<pair<int, int> > q;

    q.push(src);
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 0;

    while (!q.empty()) {
        pair<int, int> pr = q.front();
        q.pop();

        int si = pr.first, sj = pr.second;
        int lvl = level[si][sj];

        if (grid[si][sj] == 'E') {
            cout << lvl << endl;
            break;
        }
        // move 
        for (int k = 0; k < direction.size(); k++) {
            pair<int, int> move = direction[k];
            int i = si + move.first, j = sj + move.second;
            if (isValid(i, j)) {
                q.push({ i, j });
                visited[i][j] = true;
                level[i][j] = lvl + 1;
            }
        }
    }
}

int main() {

    direction.push_back({ 0,1 });
    direction.push_back({ 1,0 });
    direction.push_back({ 0,-1 });
    direction.push_back({ -1,0 });

    while (cin >> n) {
        pair<int, int> src;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'S') {
                    src = { i,j };
                }
            }
        }
        memset(visited, false, sizeof(visited));
        bfs(src);
    }
    return 0;
}

