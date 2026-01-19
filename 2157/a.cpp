#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for (auto &[el, cnt] : mp) {
        if (cnt > el)
            ans += cnt - el;
        else if (cnt < el)
            ans += cnt;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
