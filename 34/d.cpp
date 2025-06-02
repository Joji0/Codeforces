#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxN = 50005;
vector<int> adj[maxN];
bool vis[maxN];
int record[maxN];
int n, r1, r2;

void solve() {
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; i++) {
        if (i == r1)
            continue;
        int k;
        cin >> k;
        adj[i].push_back(k);
        adj[k].push_back(i);
    }
    // Create dfs function that tracks the current node and node before
    function<void(int, int)> dfs = [&](int node, int before) {
        if (vis[node])
            return;
        vis[node] = true;
        record[node] = before;
        for (auto &u : adj[node]) {
            dfs(u, node);
        }
    };
    // Start dfs from the new capital
    dfs(r2, r2);
    for (int i = 1; i <= n; i++) {
        if (i == r2)
            continue;
        cout << record[i] << " \n"[i == n];
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
