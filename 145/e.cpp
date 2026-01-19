#include <bits/stdc++.h>
using namespace std;

template <typename T> struct SegmentTree {
    vector<T> t, lazy;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void push(int v, int tl, int tr) {
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
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<SegmentTree<int>> vSeg(4, SegmentTree<int>(n));
    while (m--) {
        string q;
        cin >> q;
        if (q == "count") {
            cout << vSeg[2].query(0, n - 1) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
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
