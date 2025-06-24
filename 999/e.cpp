#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[5005];
bool vis[5005];
int par[5005];
bool temp[5005];

bool checkCycle(int node) {
    temp[node] = true;
    for (auto &u : adj[node]) {
        if (u == node)
            continue;
        if (temp[u])
            return true;
        if (checkCycle(u))
            return true;
    }
    return false;
}

bool isCycle(int node) {
    memset(temp, 0, sizeof(temp));
    return checkCycle(node);
}

void dfs(int node) {
    if (vis[node])
        return;
    vis[node] = true;
    for (auto &u : adj[node]) {
        dfs(u);
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        par[v] = u;
    }
    dfs(s);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if ((!vis[i] && (par[i] == -1 || isCycle(i)))) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
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
