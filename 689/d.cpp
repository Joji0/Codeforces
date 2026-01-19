#include <bits/stdc++.h>
using namespace std;

template <class T> struct SparseTableMin {
    int N = 0, LOG = 25;
    vector<vector<T>> st;
    T f(const T &a, const T &b) const { return min(a, b); }
    void init(const vector<T> &A) {
        N = (int)A.size();
        st.assign(LOG, vector<T>(N));
        for (int j = 0; j < N; j++)
            st[0][j] = A[j];
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j + (1LL << i) - 1 < N; j++) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
            }
        }
    }
    T query(int L, int R) const {
        int len = R - L + 1;
        int lg = (int)log2(len);
        return f(st[lg][L], st[lg][R - (1 << lg) + 1]);
    }
};

template <class T> struct SparseTableMax {
    int N = 0, LOG = 25;
    vector<vector<T>> st;
    T f(const T &a, const T &b) const { return max(a, b); }
    void init(const vector<T> &A) {
        N = (int)A.size();
        st.assign(LOG, vector<T>(N));
        for (int j = 0; j < N; j++)
            st[0][j] = A[j];
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j + (1LL << i) - 1 < N; j++) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
            }
        }
    }
    T query(int L, int R) const {
        int len = R - L + 1;
        int lg = (int)log2(len);
        return f(st[lg][L], st[lg][R - (1 << lg) + 1]);
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    SparseTableMax<int64_t> sp1;
    SparseTableMin<int64_t> sp2;
    sp1.init(A), sp2.init(B);
    auto f = [&](const int &L, const int &R) -> int64_t {
        return sp1.query(L, R) - sp2.query(L, R);
    };
    int64_t ans = 0;
    for (int l = 0; l < N; l++) {
        int lf = l, rg = N - 1, best1 = -1;
        while (lf <= rg) {
            int mid = (lf + rg) / 2;
            if (f(l, mid) >= 0) {
                best1 = mid;
                rg = mid - 1;
            } else {
                lf = mid + 1;
            }
        }
        if (best1 == -1 || f(l, best1) != 0)
            continue;
        lf = l, rg = N - 1;
        int best2 = N;
        while (lf <= rg) {
            int mid = (lf + rg) / 2;
            if (f(l, mid) > 0) {
                best2 = mid;
                rg = mid - 1;
            } else {
                lf = mid + 1;
            }
        }
        ans += best2 - best1;
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
