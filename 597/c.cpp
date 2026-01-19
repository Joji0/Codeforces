#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 67;

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
    /*
     * observation: at index i we can get length j + 1 from previous dp table
     * with ndp[A[i]] = from dp we count the elements < A[i] (use segtree) and
     * we are done. The answer is sum of all elements inside dp after interating
     * K times over j.
     *
     * example: 1 2 3 5 4
     * DP table:
     * j = 1 -> 1 1 1 1 1
     * j = 2 -> 0 1 2 3 3
     * j = 3 -> 0 0 1 3 3 -> ans = 1 + 3 + 3 = 7 NICEEEE
     */
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N), dp(maxN, 0);
    for (auto &x : A) {
        cin >> x;
        dp[x] = 1;
    }
    for (int j = 2; j <= K + 1; j++) {
        vector<int64_t> ndp(maxN, 0);
        SegmentTree<int64_t> seg(maxN);
        seg.build(ndp);
        for (int i = 0; i < N; i++) {
            ndp[A[i]] = seg.sum(1, A[i] - 1);
            seg.update(A[i], dp[A[i]]);
        }
        swap(dp, ndp);
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
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
