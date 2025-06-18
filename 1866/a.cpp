#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, ans = 1e5 + 5;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ans = min(ans, abs(val));
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
