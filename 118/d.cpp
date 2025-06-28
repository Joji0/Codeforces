#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 100000000;
int memo[105][105][3][15], k1, k2;

ll dp(int n1, int n2, int prev, int streak) {
    if (n1 == 0 && n2 == 0)
        return 1;
    if (memo[n1][n2][prev][streak] != -1)
        return memo[n1][n2][prev][streak];
    ll res = 0LL;
    if (!prev) {
        if (n1) {
            res += dp(n1 - 1, n2, 1, 1) % MOD;
        }
        if (n2) {
            res += dp(n1, n2 - 1, 2, 1) % MOD;
        }
        return res % MOD;
    } else {
        if (prev == 1) {
            if (n2)
                res += dp(n1, n2 - 1, 2, 1) % MOD;
            if (streak < k1 && n1) {
                res += dp(n1 - 1, n2, 1, streak + 1) % MOD;
            }
        } else {
            if (n1) {
                res += dp(n1 - 1, n2, 1, 1) % MOD;
            }
            if (streak < k2 && n2) {
                res += dp(n1, n2 - 1, 2, streak + 1) % MOD;
            }
        }
    }
    return memo[n1][n2][prev][streak] = res % MOD;
}

void solve() {
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(memo, -1, sizeof(memo));
    cout << dp(n1, n2, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
