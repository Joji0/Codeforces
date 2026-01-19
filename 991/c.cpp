#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    int64_t l = 1, r = n, ans = -1;
    auto ok = [&](int64_t mid) -> bool {
        int64_t cp = n, ate = 0;
        while (cp > 0) {
            int64_t now = min(mid, cp);
            ate += now;
            cp -= now;
            cp = cp - cp / 10;
        }
        return 2 * ate >= n;
    };
    while (l <= r) {
        int64_t mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    assert(ans != -1);
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
