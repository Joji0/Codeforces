#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    int mx, mn;
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    ret.mx = max(a.mx, b.mx);
    ret.mn = min(a.mn, b.mn);
    return ret;
}

struct SegmentTree {
    vector<Node> t;
    int n;
    SegmentTree(int n) {
        this->n = n;
        Node base;
        base.mx = -INF, base.mn = INF;
        t.assign(4 * n, base);
    }
    void build(const vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v].mx = a[tl];
            t[v].mn = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<int> &a) { build(a, 1, 0, n - 1); }
    Node query(int v, int tl, int tr, int l, int r) {
        Node bad;
        bad.mx = -INF, bad.mn = INF;
        if (l > r)
            return bad;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        Node lf = query(v * 2, tl, tm, l, min(r, tm));
        Node rg = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return merge(lf, rg);
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int find(int v, int tl, int tr, int l, int r, int x) {
        if (l > r || r < tl || l > tr)
            return -1;
        if (l <= tl && tr <= r) {
            if (t[v].mx == x && t[v].mn == x)
                return -1;
            if (tl == tr)
                return tl;
        }
        int tm = (tl + tr) / 2;
        int ltry = find(v * 2, tl, tm, l, min(r, tm), x);
        if (ltry != -1)
            return ltry;
        return find(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
    int find(int l, int r, int x) { return find(1, 0, n - 1, l, r, x); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    SegmentTree seg(n);
    seg.build(A);
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        Node now = seg.query(l, r);
        if (now.mx == x && now.mn == x) {
            cout << "-1\n";
        } else {
            cout << seg.find(l, r, x) + 1 << '\n';
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
