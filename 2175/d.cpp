#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    vector<int> earliest(k + 2, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int v = 1; v <= min(A[i], k); v++) {
            earliest[v] = i;
        }
    }
    vector<array<int, 2>> events;
    for (int v = 1; v <= k; v++) {
        if (earliest[v] < n) {
            if (events.empty() || events.back()[0] != earliest[v]) {
                events.push_back({earliest[v], v});
            } else {
                events.back()[1] = v;
            }
        }
    }
    vector<vector<int64_t>> dp(k + 1, vector<int64_t>(k + 2, -INF));
    dp[0][0] = 0;
    for (auto &[pos, maxV] : events) {
        int64_t mult = n - pos;
        vector<vector<int64_t>> pref(k + 1, vector<int64_t>(k + 2, -INF));
        for (int j = 0; j <= k; j++) {
            int64_t mx = -INF;
            for (int m = 0; m <= k; m++) {
                pref[j][m] = mx;
                if (dp[j][m] != -INF) {
                    mx = max(mx, dp[j][m] - m * mult);
                }
            }
            pref[j][k + 1] = mx;
        }
        for (int i = k; i >= 1; i--) {
            for (int v = 1; v <= min(maxV, i); v++) {
                int j = i - v;
                if (pref[j][v] != -INF) {
                    int64_t val = pref[j][v] + v * mult;
                    dp[i][v] = max(dp[i][v], val);
                }
            }
        }
    }
    int64_t ans = 0;
    for (int j = 0; j <= k; j++) {
        for (int m = 0; m <= k; m++) {
            if (dp[j][m] != -INF)
                ans = max(ans, dp[j][m]);
        }
    }
    cout << ans << '\n';
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
