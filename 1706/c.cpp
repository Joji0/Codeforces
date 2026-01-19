#include <bits/stdc++.h>
using namespace std;

struct State {
    int64_t cnt, cost;
};

void solve() {
    int n;
    cin >> n;
    vector<int64_t> H(n), C(n, 0);
    for (auto &x : H)
        cin >> x;
    for (int i = 1; i < n - 1; i++) {
        C[i] = max(0LL, max(H[i - 1], H[i + 1]) - H[i] + 1);
    }
    vector<vector<State>> dp(n, vector<State>(2, {0, 0}));
    dp[1][0].cnt = 0;
    dp[1][0].cost = 0;
    dp[1][1].cnt = 1;
    dp[1][1].cost = C[1];
    for (int i = 2; i < n - 1; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                // free to take
                if (dp[i - 1][0].cnt > dp[i - 1][1].cnt) {
                    dp[i][j] = dp[i - 1][0];
                } else if (dp[i - 1][1].cnt > dp[i - 1][0].cnt) {
                    dp[i][j] = dp[i - 1][1];
                } else {
                    dp[i][j] =
                        (dp[i - 1][0].cost < dp[i - 1][1].cost ? dp[i - 1][0]
                                                               : dp[i - 1][1]);
                }
            } else {
                // must limit ourselves to j = 0 before at i - 1
                dp[i][j] = dp[i - 1][0];
                dp[i][j].cost += C[i];
                dp[i][j].cnt++;
            }
        }
    }
    if (dp[n - 2][0].cnt > dp[n - 2][1].cnt) {
        cout << dp[n - 2][0].cost << '\n';
    } else if (dp[n - 2][1].cnt > dp[n - 2][0].cnt) {
        cout << dp[n - 2][1].cost << '\n';
    } else {
        cout << min(dp[n - 2][0].cost, dp[n - 2][1].cost) << '\n';
    }
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
