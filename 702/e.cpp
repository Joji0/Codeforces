#include <bits/stdc++.h>
using namespace std;

const int LOG = 35;
const int64_t INF = 1e18;

struct State {
    int node;
    int64_t s, m;
    State(int node, int64_t x, int64_t y) : node(node), s(x), m(y) {}
};

void solve() {
    int N;
    int64_t K;
    cin >> N >> K;
    vector<int> F(N);
    vector<int64_t> W(N);
    for (auto &x : F)
        cin >> x;
    for (auto &x : W)
        cin >> x;
    vector<array<int64_t, 2>> ans(N);
    vector<vector<State>> dp(LOG, vector<State>(N, State(-1, 0, INF)));
    for (int i = 0; i < N; i++) {
        State now = {F[i], W[i], W[i]};
        dp[0][i] = now;
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < N; i++) {
            dp[j][i].node = dp[j - 1][dp[j - 1][i].node].node;
            dp[j][i].s = dp[j - 1][i].s + dp[j - 1][dp[j - 1][i].node].s;
            dp[j][i].m = min(dp[j - 1][i].m, dp[j - 1][dp[j - 1][i].node].m);
        }
    }
    for (int i = 0; i < N; i++) {
        int curr = i;
        int64_t s = 0, mn = INF;
        for (int j = LOG - 1; j >= 0; j--) {
            if (K & (1LL << j)) {
                s += dp[j][curr].s;
                mn = min(mn, dp[j][curr].m);
                curr = dp[j][curr].node;
            }
        }
        ans[i][0] = s;
        ans[i][1] = mn;
    }
    for (auto &[x, y] : ans) {
        cout << x << " " << y << '\n';
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
