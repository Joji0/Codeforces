#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;

void solve() {
    /*
     * observation: This can be solved with push DP. We iterate the sum from 0
     * to N and check every possible weight from 1 to K. If we are at a weight
     * with W >= D we can do a push DP towards current sum + W with state valid
     * (1) else we update the invalid state (0). The validity will remain for a
     * weight that has be validated before hence we also push the current sum to
     * sum + W for sum state valid.
     */
    int N, K, D;
    cin >> N >> K >> D;
    auto f = [](int64_t &now, const int64_t &prev) {
        now += (prev) % MOD;
        now %= MOD;
    };
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int w = 1; w <= K; w++) {
            if (i + w <= N) {
                if (w >= D) {
                    f(dp[i + w][1], dp[i][0]);
                } else {
                    f(dp[i + w][0], dp[i][0]);
                }
                f(dp[i + w][1], dp[i][1]);
            }
        }
    }
    cout << dp[N][1] % MOD << '\n';
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
