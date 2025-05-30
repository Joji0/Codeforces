#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> grid, vis;
vector<int> ans;
int n, m;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y, int &cnt) {
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
            !(grid[x][y] & (1 << i))) {
            dfs(nx, ny, cnt);
        }
    }
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                int cnt = 0;
                dfs(i, j, cnt);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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
