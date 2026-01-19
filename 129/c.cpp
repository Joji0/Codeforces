#include <bits/stdc++.h>
using namespace std;

const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0},
          dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

void solve() {
    vector<vector<char>> grid(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }
    bool ok = false;
    auto blocked = [&](int x, int y, int t) -> bool {
        int prev = x - t;
        if (prev < 0)
            return false;
        return grid[prev][y] == 'S';
    };
    vector<vector<vector<bool>>> vis(
        8, vector<vector<bool>>(8, vector<bool>(67, false)));
    function<void(int, int, int)> dfs = [&](int x, int y, int turn) {
        if (turn > 60)
            return;
        if (turn % 2 == 0) {
            if (vis[x][y][turn])
                return;
            vis[x][y][turn] = true;
            for (int i = 0; i < 9; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    if (grid[nx][ny] == 'A') {
                        ok = true;
                        return;
                    } else if (!blocked(nx, ny, turn / 2)) {
                        dfs(nx, ny, turn + 1);
                    }
                }
            }
        } else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (grid[i][j] == 'S') {
                        if (i + turn / 2 + 1 == x && j == y) {
                            return;
                        }
                    }
                }
            }
            dfs(x, y, turn + 1);
        }
    };
    dfs(7, 0, 0);
    cout << (ok ? "WIN\n" : "LOSE\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
