#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;
    int64_t ans = 0;
    for (int64_t s = A + B; s <= B + C; s++) {
        int64_t mn = max(A, s - C), mx = min(B, s - B), res1 = 0, res2 = 0;
        if (mn <= mx) {
            res1 = mx - mn + 1;
        }
        if (s > C) {
            res2 = min(D - C + 1, s - C);
        }
        ans += res1 * res2;
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
