#include <bits/stdc++.h>
using namespace std;

struct Node {
    int64_t mask;
    Node(int64_t n = 0) : mask(n) {}
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    ret.mask = a.mask | b.mask;
    return ret;
}

struct SegmentTree {
    vector<Node> t, lazy;
    vector<int64_t> A;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, Node()), lazy.assign(4 * n, Node(-1));
    }
    void apply(int v, Node val) {
        t[v].mask = val.mask;
        lazy[v] = val;
    }
    void push(int v, int tl, int tr) {
        if (tl == tr || lazy[v].mask == -1)
            return;
        apply(v * 2, lazy[v]);
        apply(v * 2 + 1, lazy[v]);
        lazy[v].mask = -1;
    }
    void build(const vector<int64_t> &A, int v, int tl, int tr) {
        lazy[v].mask = -1;
        if (tl == tr) {
            t[v].mask = (1LL << (A[tl] - 1));
        } else {
            int tm = (tl + tr) / 2;
            build(A, v * 2, tl, tm);
            build(A, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<int64_t> &A) { build(A, 1, 0, n - 1); }
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return Node(0);
        if (l == tl && r == tr) {
            return t[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(tm, r)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int v, int tl, int tr, int l, int r, int64_t color) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            apply(v, Node(1LL << (color - 1)));
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), color);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, color);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int l, int r, int color) { update(1, 0, n - 1, l, r, color); }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Tree(N);
    vector<int64_t> A(N), tin(N), tout(N), flatten(N);
    for (auto &x : A)
        cin >> x;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    int64_t timer = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        tin[node] = timer;
        flatten[timer] = A[node];
        timer++;
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            dfs(nxt, node);
        }
        tout[node] = timer;
    };
    dfs(0, -1);
    SegmentTree seg(N);
    seg.build(flatten);
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            int64_t c;
            cin >> v >> c;
            v--;
            seg.update(tin[v], tout[v] - 1, c);
        } else {
            int v;
            cin >> v;
            v--;
            cout << __builtin_popcountll(seg.query(tin[v], tout[v] - 1).mask)
                 << '\n';
        }
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
