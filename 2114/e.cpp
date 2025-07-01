#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> adj[200005];
ll n, d[200005], dpmin[200005], dpmax[200005];
bool vis[200005];

void dfs(int node, int par) {
    if (vis[node]) {
        return;
    }
    vis[node] = true;
    dpmin[node] = min(d[node], d[node] - dpmax[par]);
    dpmax[node] = max(d[node], d[node] - dpmin[par]);
    for (auto &u : adj[node]) {
        dfs(u, node);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
        dpmax[i] = dpmin[i] = d[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << dpmax[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
