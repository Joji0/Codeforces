#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll x) {
    ll ret = 0;
    while (x) {
        if (x % 2) {
            x--;
            ret++;
        }
        x /= 2;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[f(x)]++;
    }
    ll ans = 0LL;
    for (auto &[_, b] : mp) {
        ans += b * (b - 1) / 2;
    }
    cout << ans << '\n';
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
