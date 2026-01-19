#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

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
    int64_t K;
    cin >> N >> M >> K;
    vector<Edge> Edges(M);
    for (int i = 0; i < M; i++) {
        cin >> Edges[i].u >> Edges[i].v >> Edges[i].w;
    }
    sort(Edges.begin(), Edges.end(), [&](const Edge &a, const Edge &b) {
        return max(0LL, a.w - K) < max(0LL, b.w - K);
    });
    DSU dsu(N + 1);
    bool ok = false;
    int64_t cost = 0, take = 0;
    for (int i = 0; i < M; i++) {
        Edge now = Edges[i];
        if (dsu.find(now.u) == dsu.find(now.v))
            continue;
        ok |= now.w >= K;
        dsu.join(now.u, now.v);
        cost += max(0LL, now.w - K);
        take++;
        if (take == N - 1)
            break;
    }
    int64_t mn = -1, mx = INF;
    for (int i = 0; i < M; i++) {
        Edge now = Edges[i];
        if (now.w < K) {
            mn = max(mn, now.w);
        } else {
            mx = min(mx, now.w);
        }
    }
    if (ok) {
        cout << cost << '\n';
    } else {
        cout << cost + min(K - mn, mx - K) << '\n';
    }
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
