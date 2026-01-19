#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        ans += mp[now ^ x];
        mp[now]++;
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
