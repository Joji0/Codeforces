#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    if (n >= m) {
        cout << "YES\n";
        return;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++) {
        dp[i][A[i - 1] % m] = true;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][(j + A[i - 1]) % m] =
                dp[i][(j + A[i - 1]) % m] || dp[i - 1][j];
            dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
    }
    cout << (dp[n][0] ? "YES\n" : "NO\n");
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
