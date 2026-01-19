#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int64_t ans = 1;
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(3, 1));
    for (int i = 2; i <= n; i++) {
        if (A[i] > A[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = 1;
        }
        dp[i][2] = dp[i - 1][0] + 1;
        if (A[i] > A[i - 1]) {
            dp[i][1] = dp[i - 1][1] + 1;
        } else {
            dp[i][1] = 2;
        }
        if (i >= 3 && A[i] > A[i - 2] + 1) {
            dp[i][1] = max(dp[i][1], dp[i - 2][0] + 2);
        }
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp[i][j]);
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
