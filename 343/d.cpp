#include <bits/stdc++.h>
using namespace std;

template <typename T> struct SegmentTree {
    vector<T> t;
    int n;
    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, 0);
    }
    void build(const vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(const vector<T> &a) { build(a, 1, 0, n - 1); }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            t[v] = max(t[v], new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, T new_val) { update(1, 0, n - 1, pos, new_val); }
};

template <typename T> struct SegmentTreeLazy {
    vector<T> t;
    vector<bool> marked;
    int n;
    SegmentTreeLazy(int n) {
        this->n = n;
        t.assign(4 * n, 0);
        marked.assign(4 * n, false);
    }
    void build(const vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = 0;
        }
    }
    void build(const vector<T> &a) { build(a, 1, 0, n - 1); }
    void push(int v) {
        if (marked[v]) {
            t[v * 2] = t[v * 2 + 1] = t[v];
            marked[v * 2] = marked[v * 2 + 1] = true;
            marked[v] = false;
        }
    }
    T get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get(v * 2, tl, tm, pos);
        else
            return get(v * 2 + 1, tm + 1, tr, pos);
    }
    T get(int pos) { return get(1, 0, n - 1, pos); }
    void update(int v, int tl, int tr, int l, int r, T new_val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), new_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
        }
    }
    void update(int l, int r, T new_val) { update(1, 0, n - 1, l, r, new_val); }
};

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> Tree(N);
    vector<int> tin(N), tout(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
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
    vector<int> flat(N, 0);
    timer = 0;
    SegmentTree<int> segMax(N);
    SegmentTreeLazy<int> segLazy(N);
    segMax.build(flat);
    segLazy.build(flat);
    int Q;
    cin >> Q;
    while (Q--) {
        int c, v;
        cin >> c >> v;
        v--;
        timer++;
        if (c == 1) {
            segLazy.update(tin[v], tout[v] - 1, timer);
        } else if (c == 2) {
            segMax.update(tin[v], timer);
        } else {
            int tEmpty = segMax.query(tin[v], tout[v] - 1);
            if (tEmpty >= segLazy.get(tin[v])) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
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
