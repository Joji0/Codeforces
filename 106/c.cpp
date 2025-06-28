#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[12], b[12], c[12], d[12], memo[12][1005], m;

ll dp(int i, int n) {
    if (i > m)
        return 0;
    if (memo[i][n] != -1)
        return memo[i][n];
    ll res = 0;
    for (int t = 0; t <= a[i] / b[i]; t++) {
        if (n - t * c[i] >= 0)
            res = max(res, dp(i + 1, n - t * c[i]) + t * d[i]);
    }
    return memo[i][n] = res;
}

void solve() {
    int n;
    cin >> n >> m;
    cin >> c[0] >> d[0];
    a[0] = n;
    b[0] = c[0];
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, n) << '\n';
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
