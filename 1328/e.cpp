#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Tree(N), up(N, vector<int>(LOG, -1));
    vector<int> depth(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            depth[nxt] = depth[node] + 1;
            up[nxt][0] = node;
            for (int j = 1; j < LOG; j++) {
                up[nxt][j] =
                    (up[nxt][j - 1] == -1 ? -1 : up[up[nxt][j - 1]][j - 1]);
            }
            dfs(nxt, node);
        }
    };
    dfs(0, -1);
    auto LCA = [&](int a, int b) -> int {
        if (depth[a] < depth[b])
            swap(a, b);
        int k = depth[a] - depth[b];
        for (int j = LOG - 1; j >= 0; j--) {
            if (k & (1LL << j)) {
                a = up[a][j];
            }
        }
        if (a == b)
            return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    };
    while (M--) {
        int K;
        cin >> K;
        vector<int> A(K);
        int mxd = -1, mx = -1;
        for (auto &x : A) {
            cin >> x;
            x--;
            if (depth[x] > mxd) {
                mxd = depth[x];
                mx = x;
            }
        }
        assert(mx != -1);
        bool ok = true;
        for (auto &x : A) {
            if (x == mx)
                continue;
            int lca = LCA(x, mx);
            ok &= (depth[x] - depth[lca] <= 1);
        }
        cout << (ok ? "YES\n" : "NO\n");
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
