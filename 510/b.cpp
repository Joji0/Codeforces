#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, initx, inity;
vector<vector<char>> grid;
vector<vector<bool>> vis;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y, int px, int py, char c) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == c) {
            if (nx == px && ny == py)
                continue;
            if (vis[nx][ny])
                return true;
            if (dfs(nx, ny, x, y, c)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (dfs(i, j, -1, -1, grid[i][j])) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
