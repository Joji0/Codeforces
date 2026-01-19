#include <bits/stdc++.h>
using namespace std;

// Hell nah this problem makes me cry

const int LOG = 20, maxA = 10;

struct State {
    int node;
    vector<int> topA;
};

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> Tree(N);
    vector<int> C(M), depth(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    for (auto &x : C) {
        cin >> x;
        x--;
    }
    map<int, vector<int>> pips;
    for (int i = 0; i < M; i++) {
        pips[C[i]].push_back(i + 1);
    }
    vector<vector<int>> up(LOG, vector<int>(N));
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            depth[nxt] = depth[node] + 1;
            up[0][nxt] = node;
            for (int i = 1; i < LOG; i++) {
                up[i][nxt] = up[i - 1][up[i - 1][nxt]];
            }
            dfs(nxt, node);
        }
    };
    dfs(0, -1);
    auto lift = [&](int a, int k) -> int {
        for (int i = LOG - 1; i >= 0; i--) {
            if (k & (1 << i)) {
                a = up[i][a];
            }
        }
        return a;
    };
    auto LCA = [&](int a, int b) {
        if (depth[a] < depth[b])
            swap(a, b);
        int k = depth[a] - depth[b];
        a = lift(a, k);
        if (a == b)
            return a;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][a] != up[i][b]) {
                a = up[i][a];
                b = up[i][b];
            }
        }
        return up[0][a];
    };
    auto merge = [&](vector<int> &a, vector<int> &b) -> vector<int> {
        vector<int> ret;
        ret = a;
        for (auto &x : b)
            ret.push_back(x);
        sort(ret.begin(), ret.end());
        if ((int)a.size() + (int)b.size() > 10)
            ret.resize(10);
        return ret;
    };
    vector<vector<State>> dp(LOG, vector<State>(N));
    for (int i = 0; i < N; i++) {
        State now;
        now.topA.clear();
        for (int j = 0; j < min(maxA, (int)pips[i].size()); j++) {
            now.topA.push_back(pips[i][j]);
        }
        now.node = up[0][i];
        dp[0][i] = now;
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < N; j++) {
            int mid = dp[i - 1][j].node;
            dp[i][j].topA = merge(dp[i - 1][j].topA, dp[i - 1][mid].topA);
            dp[i][j].node = up[i][j];
        }
    }
    auto f = [&](int k, int node) -> vector<int> {
        vector<int> ret;
        for (int i = LOG - 1; i >= 0; i--) {
            if (k & (1 << i)) {
                ret = merge(ret, dp[i][node].topA);
                node = up[i][node];
            }
        }
        return ret;
    };
    while (Q--) {
        int u, v, a;
        cin >> u >> v >> a;
        u--, v--;
        int lca = LCA(u, v);
        int ku = depth[u] - depth[lca], kv = depth[v] - depth[lca];
        vector<int> ans = f(ku, u), fv = f(kv, v);
        auto it = pips.find(lca);
        vector<int> vlca;
        if (it != pips.end()) {
            vlca = it->second;
            vlca.resize(min((int)vlca.size(), 10));
        }
        ans = merge(ans, fv);
        ans = merge(ans, vlca);
        int sz = min(a, (int)ans.size());
        cout << sz << " ";
        for (int i = 0; i < sz; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
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
