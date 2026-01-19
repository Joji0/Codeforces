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
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void build(const vector<T> &a) { build(a, 1, 0, n - 1); }
    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) +
               sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    T sum(int l, int r) { return sum(1, 0, n - 1, l, r); }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    void update(int pos, T new_val) { update(1, 0, n - 1, pos, new_val); }
};

void solve() {
    int n;
    cin >> n;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    vector<int64_t> A, empty(n, 0), sorted;
    for (auto &[a, b] : mp) {
        A.push_back(b);
    }
    sorted = A;
    sort(sorted.begin(), sorted.end());
    int64_t ans = 0;
    SegmentTree<int64_t> seg(n);
    seg.build(empty);
    auto get = [&](const int64_t &x) -> int {
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    };
    for (auto &x : A) {
        ans += seg.sum(get(x), n - 1);
        seg.update(get(x), 1);
    }
    cout << ans << '\n';
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
