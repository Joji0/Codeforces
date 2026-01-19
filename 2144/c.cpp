#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    vector<int> Mn(n), Mx(n);
    for (int i = 0; i < n; i++) {
        Mn[i] = min(A[i], B[i]);
        Mx[i] = max(A[i], B[i]);
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int pA = (j ? Mn[i - 1] : Mx[i - 1]);
            int pB = (j ? Mx[i - 1] : Mn[i - 1]);
            if (A[i] >= pA && B[i] >= pB) {
                dp[i][0] += dp[i - 1][j] % MOD;
            }
            if (B[i] >= pA && A[i] >= pB) {
                dp[i][1] += dp[i - 1][j] % MOD;
            }
        }
    }
    cout << (dp[n - 1][0] % MOD + dp[n - 1][1] + MOD) % MOD << '\n';
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
