#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    string s;
    cin >> N >> s >> Q;
    vector<vector<int>> dp(N + 1, vector<int>(26)), pref(N, vector<int>(26));
    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < N; i++) {
            pref[i][j] = (i ? pref[i - 1][j] : 0) + (s[i] - 'a' != j);
        }
    }
    for (int j = 0; j < 26; j++) {
        for (int l = 0; l < N; l++) {
            for (int r = l; r < N; r++) {
                int change = pref[r][j] - (l ? pref[l - 1][j] : 0);
                dp[change][j] = max(dp[change][j], r - l + 1);
            }
        }
    }
    for (int j = 0; j < 26; j++) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    while (Q--) {
        int nm;
        char nc;
        cin >> nm >> nc;
        cout << dp[nm][nc - 'a'] << '\n';
    }
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
