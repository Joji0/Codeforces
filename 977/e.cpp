#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Graph(N);
    vector<int> indeg(N, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Graph[u].push_back(v), Graph[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
    bool ok = true;
    vector<bool> vis(N, false);
    function<void(int, int, int &)> dfs = [&](int node, int par, int &cnt) {
        if (vis[node])
            return;
        vis[node] = true;
        cnt++;
        if (indeg[node] != 2)
            ok = false;
        for (auto &nxt : Graph[node]) {
            if (nxt == par)
                continue;
            dfs(nxt, node, cnt);
        }
    };
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!vis[i] && indeg[i] == 2) {
            ok = true;
            int cnt = 0;
            dfs(i, -1, cnt);
            if (ok && cnt >= 3) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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
