#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int N, P, K;
    cin >> N >> P >> K;
    vector<int64_t> A(N);
    vector<vector<int64_t>> player(N, vector<int64_t>(P));
    for (auto &x : A)
        cin >> x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            cin >> player[i][j];
        }
    }
    vector<int64_t> dp(1 << P, -INF);
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](const auto &a, const auto &b) { return A[a] > A[b]; });
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int now = idx[i];
        vector<int64_t> ndp = dp;
        for (int mask = 0; mask < (1 << P); mask++) {
            if (dp[mask] == -INF)
                continue;
            int cnt = __builtin_popcount(mask);
            int64_t bonus = 0;
            if (i - cnt < K)
                bonus += A[now];
            ndp[mask] = max(ndp[mask], dp[mask] + bonus);
            for (int j = 0; j < P; j++) {
                if (!(mask & (1 << j))) {
                    ndp[mask | (1 << j)] =
                        max(ndp[mask | (1 << j)], dp[mask] + player[now][j]);
                }
            }
        }
        swap(dp, ndp);
    }
    cout << dp[(1 << P) - 1] << '\n';
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
