/*
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
Ans: 6

7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
Ans: 13

11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
Ans : 59

. - land.
# - water.
@ - initial position of the prince (appears exactly once in a dataset).
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 22;
char grid[N][N];
bool visited[N][N];
int h, w;

vector<pair<int, int>> moves = { { 0, 1 }, {0, -1}, {-1, 0}, {1, 0} };;


bool isValid(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w && !visited[i][j] && grid[i][j] != '#';
}


void dfs(pair<int, int> src, int& count) {
    count++;
    visited[src.first][src.second] = true;
    for (auto move : moves) {
        int i = src.first + move.first, j = src.second + move.second;
        if (isValid(i, j)) {
            dfs({ i, j }, count);
        }
    }
}

int main() {

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> w >> h;
        pair<int, int> src;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') {
                    src = { i, j };
                }
            }
        }

        int count = 0;
        memset(visited, false, sizeof(visited));
        dfs(src, count);
        cout << "Case " << i << ": " << count << endl;
    }
    return 0;
}