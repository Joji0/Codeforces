#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int64_t>> dp(n, vector<int64_t>(26, INF));
    for (int i = 0; i < 26; i++) {
        dp[0][i] = ((char)('a' + i) != s[0]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (j != k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }
            }
            if ((char)('a' + j) != s[i]) {
                dp[i][j]++;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    // cerr << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';

    // search parent
    string ans(n, 'a');
    auto it = min_element(dp[n - 1].begin(), dp[n - 1].end());
    ans[n - 1] = (char)('a' + (it - dp[n - 1].begin()));
    int prev = it - dp[n - 1].begin();
    for (int i = n - 2; i >= 0; i--) {
        int need = *min_element(dp[i].begin(), dp[i].end());
        bool found = false;
        for (int j = 0; j < 26; j++) {
            if (dp[i][j] == need && j != prev) {
                prev = j;
                ans[i] = (char)('a' + j);
                found = true;
                break;
            }
        }
        if (!found) {
            need++;
            for (int j = 0; j < 26; j++) {
                if (dp[i][j] == need && j != prev) {
                    prev = j;
                    ans[i] = (char)('a' + j);
                    found = true;
                    break;
                }
            }
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
