#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> C(n);
    vector<vector<int>> G(n);
    map<int, set<int>> ans;
    for (auto &x : C)
        cin >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int node) {
        vis[node] = true;
        set<int> &now = ans[C[node]];
        for (auto &nxt : G[node]) {
            if (vis[nxt]) {
                if (C[nxt] != C[node]) {
                    now.insert(C[nxt]);
                }
            } else {
                if (C[nxt] != C[node]) {
                    now.insert(C[nxt]);
                }
                dfs(nxt);
            }
        }
        return;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i);
    }
    int best = 0;
    for (auto &[c, st] : ans) {
        best = max(best, (int)st.size());
        // cerr << c << " " << cnt << '\n';
    }
    for (auto &[c, st] : ans) {
        if ((int)st.size() == best) {
            cout << c << '\n';
            return;
        }
    }
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
