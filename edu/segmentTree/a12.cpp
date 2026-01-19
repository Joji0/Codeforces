#include <bits/stdc++.h>
using namespace std;

struct Node {
    int64_t best, pref, suff, sum;
    Node() : best(0), pref(0), suff(0), sum(0) {}
    Node(int64_t v) : best(v), pref(v), suff(v), sum(v) {}
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    ret.best = max({a.best, b.best, a.suff + b.pref});
    ret.pref = max({a.pref, a.sum + b.pref});
    ret.suff = max({b.suff, a.suff + b.sum});
    ret.sum = a.sum + b.sum;
    return ret;
}

struct SegmentTree {
    vector<Node> t;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, Node());
    }
    void build(const vector<int64_t> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = Node(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<int64_t> &a) { build(a, 1, 0, n - 1); }
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return Node();
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int v, int tl, int tr, int pos, int64_t new_val) {
        if (tl == tr) {
            t[v] = Node(new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, int64_t new_val) { update(1, 0, n - 1, pos, new_val); }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    SegmentTree seg(N);
    seg.build(A);
    while (Q--) {
        int i;
        int64_t v;
        cin >> i >> v;
        cout << max(0LL, seg.query(0, N - 1).best) << '\n';
        seg.update(i, v);
    }
    cout << max(0LL, seg.query(0, N - 1).best) << '\n';
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
