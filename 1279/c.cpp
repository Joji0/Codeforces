#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (auto &x : A) {
        cin >> x;
        x--;
    }
    for (auto &x : B) {
        cin >> x;
        x--;
    }
    vector<int> mp(n);
    for (int i = 0; i < n; i++) {
        mp[A[i]] = i;
    }
    int64_t ans = 0;
    int prev = 0;
    for (int i = 0; i < m; i++) {
        if (mp[B[i]] < prev) {
            ans++;
        } else {
            ans += 2 * (mp[B[i]] - i) + 1;
            prev = mp[B[i]] + 1;
        }
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
