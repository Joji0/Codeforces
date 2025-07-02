#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int64_t dp[10][200005];

void solve() {
    int m;
    string n;
    cin >> n >> m;
    int64_t ans = 0;
    for (auto &ch : n) {
        ans += dp[ch - '0'][m] % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 10; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 200000; i++) {
        for (int d = 0; d <= 8; d++) {
            // The transition is saying that to get to dp[d][i] we have to apply
            // i - 1 operation to d + 1, i.e., dp[d + 1][i - 1]
            dp[d][i] = dp[d + 1][i - 1];
        }
        dp[9][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
