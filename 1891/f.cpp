#include <bits/stdc++.h>
using namespace std;

struct Query {
    int t, v, newNode;
    int64_t x;
};

template <typename T> struct SegmentTree {
    vector<T> t, lazy;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void push(int v, int tl, int tr) {
        if (lazy[v] == 0 || tl == tr)
            return;
        int tm = (tl + tr) / 2;
        t[v * 2] += lazy[v] * (tm - tl + 1);
        t[v * 2 + 1] += lazy[v] * (tr - tm);
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    void build(const vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void build(const vector<T> &a) { build(a, 1, 0, n - 1); }
    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) +
               sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    T sum(int l, int r) { return sum(1, 0, n - 1, l, r); }
    T get(int pos) { return sum(1, 0, n - 1, pos, pos); }
    void update(int v, int tl, int tr, int l, int r, T add) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += add * (tr - tl + 1);
            lazy[v] += add;
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void update(int l, int r, T add) { update(1, 0, n - 1, l, r, add); }
};

void solve() {
    /*
     * observation: I think we need to this in offline mode since allocating
     * child vertex will be tricky in online mode. In offline mode we need to
     * gather information regarding tin and tout for the euler tour and this
     * will work fine since adding to a subtree of v will finally be rewritten
     * when adding that vertex so that the value will be reset to 0.
     */
    int Q;
    cin >> Q;
    int N = 0;
    vector<vector<int>> Tree(Q + 1);
    vector<Query> query(Q);
    for (int i = 0; i < Q; i++) {
        cin >> query[i].t;
        if (query[i].t == 1) {
            cin >> query[i].v;
            query[i].v--;
            N++;
            query[i].newNode = N;
            Tree[query[i].v].push_back(N);
        } else {
            cin >> query[i].v >> query[i].x;
            query[i].v--;
        }
    }
    vector<int> tin(N + 67), tout(N + 67);
    vector<int64_t> flat(N + 67, 0), minus(N + 67, 0);
    int timer = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        tin[node] = timer++;
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            dfs(nxt, node);
        }
        tout[node] = timer;
    };
    dfs(0, -1);
    SegmentTree<int64_t> seg(N + 67);
    seg.build(flat);
    for (int i = 0; i < Q; i++) {
        auto now = query[i];
        if (now.t == 1) {
            int u = now.newNode;
            minus[u] = -seg.get(tin[u]);
        } else {
            seg.update(tin[now.v], tout[now.v] - 1, now.x);
        }
    }
    for (int i = 0; i <= N; i++) {
        cout << seg.get(tin[i]) + minus[i] << " \n"[i == N];
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
