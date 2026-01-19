#include <bits/stdc++.h>
using namespace std;

template <typename T> struct SegmentTree {
    vector<T> t, lazy;
    int n;

    SegmentTree(int n) {
        this->n = n;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void apply(int v, int tl, int tr, int val) {
        lazy[v] = val;
        if (val == 0) {
            t[v] = 0;
        } else {
            t[v] = (tr - tl + 1);
        }
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] == -1)
            return;
        int tm = (tl + tr) / 2;
        apply(v * 2, tl, tm, lazy[v]);
        apply(v * 2 + 1, tm + 1, tr, lazy[v]);
        lazy[v] = -1;
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
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    T query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            apply(v, tl, tr, val);
            return;
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void update(int l, int r, T add) { update(1, 0, n - 1, l, r, add); }
};

void preprocess(vector<SegmentTree<int>> &v, const string &s) {
    int n = s.size();
    vector<vector<int>> temp(26, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int now = s[i] - 'a';
        temp[now][i] = 1;
    }
    for (int i = 0; i < 26; i++) {
        v[i].build(temp[i]);
    }
}

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<SegmentTree<int>> vSeg(26, SegmentTree<int>(n));
    preprocess(vSeg, s);
    auto update1 = [&](int l, int r) {
        // asc
        vector<int> cnt(26, 0);
        for (int i = 0; i < 26; i++) {
            cnt[i] = vSeg[i].query(l, r);
        }
        int cL = l, cR = l + cnt[0] - 1;
        for (int i = 0; i < 26; i++) {
            vSeg[i].update(cL, cR, 1);
            vSeg[i].update(l, cL - 1, 0);
            vSeg[i].update(cR + 1, r, 0);
            if (i + 1 < 26) {
                cL = cR + 1;
                cR = cL + cnt[i + 1] - 1;
            }
        }
    };
    auto update2 = [&](int l, int r) {
        // desc
        vector<int> cnt(26, 0);
        for (int i = 0; i < 26; i++) {
            cnt[i] = vSeg[i].query(l, r);
        }
        int cL = l, cR = l + cnt[25] - 1;
        for (int i = 25; i >= 0; i--) {
            vSeg[i].update(cL, cR, 1);
            vSeg[i].update(l, cL - 1, 0);
            vSeg[i].update(cR + 1, r, 0);
            if (i - 1 >= 0) {
                cL = cR + 1;
                cR = cL + cnt[i - 1] - 1;
            }
        }
    };
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        if (k == 1) {
            update1(l, r);
        } else {
            update2(l, r);
        }
    }
    string ans(n, 'a');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (vSeg[j].query(i, i) == 1) {
                ans[i] = (char)(j + 'a');
                break;
            }
        }
    }
    cout << ans << '\n';
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
