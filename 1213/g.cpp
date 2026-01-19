#include <bits/stdc++.h>
using namespace std;

const int maxQ = 2e5 + 67;

struct DSU {
    vector<int64_t> parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    int64_t join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            int64_t delta = sz[a] * sz[b];
            parent[b] = a;
            sz[a] += sz[b];
            return delta;
        } else {
            return 0;
        }
    }
    int saizu(const int &x) { return sz[find(x)]; }
};

struct Edge {
    int u, v, w;
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<Edge> Edges;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        Edges.push_back({u, v, w});
    }
    DSU dsu(N);
    vector<int64_t> ans(maxQ, 0);
    sort(Edges.begin(), Edges.end(),
         [](const auto &a, const auto &b) { return a.w < b.w; });
    int ptr = 0;
    for (int i = 1; i < maxQ; i++) {
        ans[i] = ans[i - 1];
        while (ptr < (int)Edges.size() && Edges[ptr].w <= i) {
            auto now = Edges[ptr];
            ans[i] += dsu.join(now.u, now.v);
            ptr++;
        }
    }
    while (M--) {
        int q;
        cin >> q;
        cout << ans[q] << " ";
    }
    cout << '\n';
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
