#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> adj[50];
bool vis[50];
int colors[50];

void solve() {
    int n, m;
    cin >> n >> m;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (adj[u].size() > 2 || adj[v].size() > 2) {
            ok = false;
        }
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    set<int> ready;
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty())
            ready.insert(i);
    }
    function<void(int, int, int &)> dfs = [&](int node, int c, int &depth) {
        if (vis[node])
            return;
        vis[node] = true;
        colors[node] = c;
        for (auto &u : adj[node]) {
            if (vis[u])
                continue;
            depth++;
            dfs(u, c, depth);
        }
    };
    int color = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int d = 1;
            dfs(i, color, d);
            if (d > 3) {
                cout << "-1\n";
                return;
            } else if (d == 2) {
                if (ready.empty()) {
                    cout << "-1\n";
                    return;
                }
                auto add = *(ready.begin());
                ready.erase(ready.begin());
                colors[add] = color;
                vis[add] = true;
            }
            // } else if (d < 2) {
            //     if (ready.size() < 2) {
            //         cout << "-1\n";
            //         return;
            //     }
            //     colors[i] = color;
            //     ready.erase(i);
            //     auto add1 = *(ready.begin());
            //     ready.erase(ready.begin());
            //     auto add2 = *(ready.begin());
            //     ready.erase(ready.begin());
            //     colors[add1] = color, colors[add2] = color;
            //     vis[add1] = true, vis[add2] = true;
            // }
            color++;
        }
    }
    if (!ready.empty()) {
        if (ready.size() % 3) {
            cout << "-1\n";
            return;
        }
        int cnt = 0;
        for (auto &u : ready) {
            colors[u] = color;
            cnt++;
            if (cnt == 3) {
                cnt = 0;
                color++;
            }
        }
    }
    for (int i = 0; i < color; i++) {
        for (int j = 1; j <= n; j++) {
            if (colors[j] == i) {
                cout << j << " ";
            }
        }
        cout << '\n';
    }
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
