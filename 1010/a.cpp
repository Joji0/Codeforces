#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld eps = 1e-10;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    auto f = [&](ld mid) -> bool {
        for (int i = 0; i < N; i++) {
            ld used = (M + mid) / (ld)(A[i]);
            mid -= used;
            if (mid < 0)
                return false;
            used = (M + mid) / (ld)(B[i]);
            mid -= used;
            if (mid < 0)
                return false;
        }
        return mid >= 0;
    };
    ld l = 0, r = 1e18, ans = -1;
    while (r - l > eps) {
        ld mid = (l + r) / 2;
        if (f(mid)) {
            ans = mid;
            r = mid - eps;
        } else {
            l = mid + eps;
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';
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
