#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    // dp[i][j] = minimal change considering prefix i and last color is j
    int N, K;
    string S, s;
    cin >> N >> K >> s;
    S = "#" + s;
    vector<vector<int>> dp(N + 1, vector<int>(K, 0));
    vector<vector<int>> par(N + 1, vector<int>(K, -1));
    for (int j = 0; j < K; j++) {
        dp[1][j] = (S[1] != (char)(j + 'A'));
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            dp[i][j] = INF;
            for (int k = 0; k < K; k++) {
                if (j == k)
                    continue;
                if (dp[i - 1][k] + (j != S[i] - 'A') < dp[i][j]) {
                    dp[i][j] = dp[i - 1][k] + (j != S[i] - 'A');
                    par[i][j] = k;
                }
            }
        }
    }
    string ans(N, 'A');
    int curr = min_element(dp[N].begin(), dp[N].end()) - dp[N].begin();
    for (int i = N; i >= 1; i--) {
        ans[i - 1] = char('A' + curr);
        curr = par[i][curr];
    }
    cout << *min_element(dp[N].begin(), dp[N].end()) << '\n';
    for (auto &x : ans) {
        cout << x;
    }
    cout << '\n';
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
