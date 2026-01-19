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

struct Edge {
    int u, v;
    int64_t w;
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<Edge> Edges(M);
    for (int i = 0; i < M; i++) {
        cin >> Edges[i].u >> Edges[i].v >> Edges[i].w;
        Edges[i].u--, Edges[i].v--;
    }
    int64_t ans = (1LL << 61) - 1;
    for (int64_t i = 60; i >= 0; i--) {
        DSU dsu(N);
        bool ok = false;
        int taken = 0;
        int64_t cand = ans & ~(1LL << i);
        for (auto &[u, v, w] : Edges) {
            if ((w | cand) != cand)
                continue;
            if (dsu.find(u) == dsu.find(v))
                continue;
            dsu.join(u, v);
            taken++;
            if (taken == N - 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans &= ~(1LL << i);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
