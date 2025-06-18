#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, r1, r2, c1, c2;
bool first = true;
vector<vector<char>> grid;
vector<vector<int>> vis;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (vis[x][y] == 2)
        return;
    if (grid[x][y] == 'X' && !first) {
        grid[x][y] = 'C';
        return;
    }
    grid[x][y] = 'X';
    if (first)
        first = false;
    vis[x][y]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] < 2 &&
            grid[nx][ny] != 'C') {
            dfs(nx, ny);
        }
    }
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    dfs(r1, c1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " \n"[j == m - 1];
        }
    }
    cout << (grid[r2][c2] == 'C' ? "YES\n" : "NO\n");
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
