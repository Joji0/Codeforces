#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int k = 0, m = 0;
    for (auto &[_, cnt] : mp) {
        if (cnt & 1)
            k++;
        else
            m++;
    }
    int ans = 0;
    if (k > 0) {
        ans = k + 2 * m;
    } else {
        if (n % 2 == m % 2)
            ans = 2 * m;
        else
            ans = 2 * (m - 1);
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
