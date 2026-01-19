#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    Node() : sum(0) {}
    Node(int val) : sum(val) {}
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    ret.sum = a.sum + b.sum;
    return ret;
}

template <typename T> struct SegmentTree {
    vector<Node> t;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, Node());
    }
    void build(const vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = Node(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<T> &a) { build(a, 1, 0, n - 1); }
    T query(int v, int tl, int tr, int l, int r, int k) {
        if (l > r)
            return -1;
        if (l == r)
            return l;
        int tm = (tl + tr) / 2;
        if (t[v * 2].sum > k) {
            return query(v * 2, tl, tm, l, min(r, tm), k);
        } else {
            return query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r,
                         k - t[v * 2].sum);
        }
    }
    T query(int l, int r, int k) { return query(1, 0, n - 1, l, r, k); }
    void update(int v, int tl, int tr, int pos, int old) {
        if (tl == tr) {
            t[v] = Node(old ^ 1);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, old);
            else
                update(v * 2 + 1, tm + 1, tr, pos, old);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, int old) { update(1, 0, n - 1, pos, old); }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    SegmentTree<int> seg(N);
    seg.build(A);
    while (M--) {
        int t, n;
        cin >> t >> n;
        if (t == 1) {
            seg.update(n, A[n]);
            A[n] ^= 1;
        } else {
            cout << seg.query(0, N - 1, n) << '\n';
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
