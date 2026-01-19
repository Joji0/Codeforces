#include <bits/stdc++.h>
using namespace std;

struct Node {
    int64_t mn;
    int occ;
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    if (a.mn < b.mn) {
        ret.mn = a.mn;
        ret.occ = a.occ;
    } else if (a.mn > b.mn) {
        ret.mn = b.mn;
        ret.occ = b.occ;
    } else {
        ret.mn = a.mn;
        ret.occ = a.occ + b.occ;
    }
    return ret;
}

struct SegmentTree {
    vector<Node> t;
    int n;
    SegmentTree(int n) {
        this->n = n;
        Node base;
        base.mn = 1e18;
        base.occ = 0;
        t.assign(4 * n, base);
    }
    void build(const vector<int64_t> &a, int v, int tl, int tr) {
        if (tl == tr) {
            Node base;
            base.mn = a[tl];
            base.occ = 1;
            t[v] = base;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<int64_t> &a) { build(a, 1, 0, n - 1); }
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            Node base;
            base.mn = 1e18;
            base.occ = 0;
            return base;
        }
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int v, int tl, int tr, int pos, int64_t new_val) {
        if (tl == tr) {
            Node base;
            base.mn = new_val;
            base.occ = 1;
            t[v] = base;
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
    int n, m;
    cin >> n >> m;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    SegmentTree seg(n);
    seg.build(A);
    while (m--) {
        int t;
        int64_t x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seg.update(x, y);
        } else {
            cout << seg.query(x, y - 1).mn << " " << seg.query(x, y - 1).occ
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
