#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 69;
vector<vector<int>> divs(maxN);

void precompute() {
    for (int mult = 1; mult < maxN; mult++) {
        for (int run = mult; run < maxN; run += mult) {
            divs[run].push_back(mult);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int64_t> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    vector<int64_t> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &x : divs[i]) {
            if (S[x] < S[i]) {
                dp[i] = max(dp[i], dp[x]);
            }
        }
        dp[i]++;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
