#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    int64_t sE = 0, sOP = 0, best = 1e18, best2 = -1e18;
    for (auto &x : A) {
        cin >> x;
        if (x > 0 && (x & 1)) {
            sOP += x;
        } else if (x > 0) {
            sE += x;
        } else if (x < 0 && (x & 1) && x > best2) {
            best2 = x;
        }
        if (x > 0 && (x & 1) && x < best) {
            best = x;
        }
    }
    int64_t ans = -1e18;
    if (sOP & 1) {
        ans = max(ans, sOP + sE);
    }
    if (best < 1e18) {
        int64_t temp = sOP - best + sE;
        if (temp & 1)
            ans = max(ans, temp);
    }
    if (best2 > -1e18) {
        int64_t temp = sE + best2;
        if (temp & 1)
            ans = max(ans, temp);
        int64_t temp2 = sE + best2 + sOP;
        if (temp2 & 1) {
            ans = max(ans, temp2);
        }
    }
    assert(ans & 1);
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
