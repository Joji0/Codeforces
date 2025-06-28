#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, b;
    cin >> n;
    vector<ll> stairs(n), pref(n + 1, 0);
    for (auto &stair : stairs)
        cin >> stair;
    cin >> b;
    vector<pair<ll, ll>> boxes(b);
    for (int i = 0; i < b; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = max(pref[i - 1], stairs[i - 1]);
    }
    for (int i = 0; i < b; i++) {
        auto &[w, h] = boxes[i];
        cout << max(pref[1], pref[w]) << '\n';
        pref[1] = max(pref[1], pref[w]) + h;
    }
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
