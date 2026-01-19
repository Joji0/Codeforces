#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    int n, m, maxW;
    cin >> n >> m >> maxW;
    vector<int64_t> W(n), B(n);
    for (auto &x : W)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.join(u, v);
    }
    vector<int64_t> G(n, 0), C(n, 0);
    vector<vector<int>> M(n);
    for (int i = 0; i < n; i++) {
        G[dsu.find(i)] += B[i];
        C[dsu.find(i)] += W[i];
        M[dsu.find(i)].push_back(i);
    }
    vector<int64_t> dp(maxW + 1, 0);
    for (int i = 0; i < n; i++) {
        if (M[i].empty())
            continue;
        vector<int64_t> ndp = dp;
        if (C[i] <= maxW) {
            for (int j = 0; j + C[i] <= maxW; j++) {
                ndp[j + C[i]] = max(ndp[j + C[i]], dp[j] + G[i]);
            }
        }
        for (auto &mem : M[i]) {
            if (W[mem] <= maxW) {
                for (int j = 0; j + W[mem] <= maxW; j++) {
                    ndp[j + W[mem]] = max(ndp[j + W[mem]], dp[j] + B[mem]);
                }
            }
        }
        swap(dp, ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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
