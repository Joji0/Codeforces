#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int64_t, int> X, Y;
    map<array<int64_t, 2>, int> Both;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int64_t x, y;
        cin >> x >> y;
        ans += X[x];
        ans += Y[y];
        ans -= Both[{x, y}];
        X[x]++;
        Y[y]++;
        Both[{x, y}]++;
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
