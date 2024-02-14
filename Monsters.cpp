#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char grid[N][N];
bool visited[N][N];
pair<int, int> path[N][N];

class Person {
public:
    int x, y;
    char n;

    Person(int x, int y, char n) {
        this->x = x;
        this->y = y;
        this->n = n;
    }
};

vector<pair<int, int>> moves = { { 0,1 }, {1,0}, {0, -1}, {-1, 0} };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#';
}

void bfs(queue<Person>& q) {
    while (!q.empty()) {
        Person front = q.front();
        q.pop();

        for (auto move : moves) {
            int ci = front.x + move.first, cj = front.y + move.second;

            if (isValid(ci, cj) && !visited[ci][cj]) {
                visited[ci][cj] = true;
                q.push(Person(ci, cj, front.n));
                grid[ci][cj] = front.n;

                if (front.n == 'A') {
                    path[ci][cj] = { move.first, move.second };
                }
            }
        }
    }
}

bool isOuter(int i, int j) {
    return i == 0 || j == 0 || i == n - 1 || j == m - 1;
}

int main() {
    queue<Person> q;
    cin >> n >> m;
    pair<int, int> src, dest;
    // grid input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                q.push(Person(i, j, 'M'));
                visited[i][j] = true;
            }

            if (grid[i][j] == 'A') {
                src = { i, j };
            }
        }
    }

    q.push(Person(src.first, src.second, 'A'));
    visited[src.first][src.second] = true;

    bfs(q);

    bool isExit = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isOuter(i, j) && grid[i][j] == 'A') {
                isExit = true;
                dest = { i, j };
                break;
            }
        }
    }

    if (isExit) {
        cout << "YES" << endl;
        vector<pair<int, int>> res;
        while (dest.first != src.first || dest.second != src.second) {
            res.push_back(path[dest.first][dest.second]);
            dest.first -= res.back().first;
            dest.second -= res.back().second;
        }
        reverse(res.begin(), res.end());
        string path;
        for (auto p : res) {
            if (make_pair(-1, 0) == p) {
                // up direction
                path.push_back('U');
            }
            else if (make_pair(1, 0) == p) {
                // down direction
                path.push_back('D');
            }
            else if (make_pair(0, -1) == p) {
                // left direction
                path.push_back('L');
            }
            else {
                // right direction
                path.push_back('R');
            }
        }
        cout << path.size() << endl;
        cout << path;
    }
    else {
        cout << "NO";
    }


    return 0;
}