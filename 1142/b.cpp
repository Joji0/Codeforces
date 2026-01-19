#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9, LOG = 25;

template <class T> struct SparseTable {
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

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> P(N), A(M);
    for (auto &x : P)
        cin >> x;
    for (auto &x : A)
        cin >> x;
    map<int, int> nxt, last;
    for (int i = 0; i < N - 1; i++) {
        nxt[P[i]] = P[i + 1];
    }
    nxt[P[N - 1]] = P[0];
    vector<int> F(M);
    for (int i = M - 1; i >= 0; i--) {
        int need = nxt[A[i]];
        if (last.contains(need)) {
            F[i] = last[need];
        } else {
            F[i] = INF;
        }
        last[A[i]] = i;
    }
    vector<vector<int>> dp(LOG, vector<int>(M, INF));
    for (int i = 0; i < M; i++) {
        dp[0][i] = F[i];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < M; j++) {
            int mid = dp[i - 1][j];
            dp[i][j] = (mid == INF ? INF : dp[i - 1][mid]);
        }
    }
    vector<int> end(M, INF);
    for (int i = 0; i < M; i++) {
        int jump = N - 1;
        int curr = i;
        for (int j = LOG - 1; j >= 0; j--) {
            if (jump & (1LL << j)) {
                curr = dp[j][curr];
                if (curr == INF) {
                    break;
                }
            }
        }
        end[i] = curr;
    }
    SparseTable<int> sparse;
    sparse.init(end);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (sparse.query(l, r) <= r ? "1" : "0");
    }
    cout << '\n';
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
