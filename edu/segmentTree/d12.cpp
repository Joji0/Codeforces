#include <bits/stdc++.h>
using namespace std;

struct Node {
    int64_t mx;
    Node() : mx(0) {}
    Node(int64_t x) : mx(x) {}
};

Node merge(const Node &a, const Node &b) { return Node(max(a.mx, b.mx)); }

struct seg {
    vector<Node> t;
    int n;
    seg(int n) {
        this->n = n;
        t.assign(4 * n, Node());
    }
    void build(const vector<int64_t> &A, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = Node(A[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(A, v * 2, tl, tm);
            build(A, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<int64_t> &A) { build(A, 1, 0, n - 1); }
    int64_t query(int v, int tl, int tr, int L, int64_t x) {
        if (tl > tr || tr < L || t[v].mx < x) {
            return -1;
        }
        if (tl == tr && t[v].mx >= x) {
            return tl;
        } else if (tl == tr && t[v].mx < x)
            return -1;
        int tm = (tl + tr) / 2;
        int64_t q1 = query(v * 2, tl, tm, L, x);
        if (q1 != -1)
            return q1;
        return query(v * 2 + 1, tm + 1, tr, L, x);
    }
    int64_t query(int L, int64_t x) { return query(1, 0, n - 1, L, x); }
    void update(int v, int tl, int tr, int pos, int64_t x) {
        if (tl == tr) {
            t[v] = Node(x);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, x);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, x);
            }
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, int64_t x) { update(1, 0, n - 1, pos, x); }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    seg seg(N);
    seg.build(A);
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            int64_t v;
            cin >> i >> v;
            seg.update(i, v);
        } else {
            int l;
            int64_t x;
            cin >> x >> l;
            cout << seg.query(l, x) << '\n';
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
