#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    unordered_map<int, int> idx, dp, par;
    int maxx = 0, last = -1;
    par[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (dp.contains(a[i] - 1)) {
            dp[a[i]] = dp[a[i] - 1] + 1;
            idx[a[i]] = i;
            par[i] = idx[a[i] - 1];
        } else {
            dp[a[i]] = 1;
            if (!idx.contains(a[i])) {
                idx[a[i]] = i;
            }
            par[i] = -1;
        }
        if (dp[a[i]] > maxx) {
            maxx = dp[a[i]];
            last = i;
        }
    }
    vector<int> ans;
    cout << maxx << '\n';
    while (last != -1) {
        ans.push_back(last == 0 ? idx[last] : last);
        last = par[last];
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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
