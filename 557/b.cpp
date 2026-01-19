#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-10;

void solve() {
    int N;
    int64_t W;
    cin >> N >> W;
    vector<long double> cups(2 * N);
    for (auto &x : cups) {
        cin >> x;
    }
    sort(cups.begin(), cups.end());
    auto f = [&](const long double &mid) -> bool {
        for (int i = 0; i < N; i++) {
            if (mid > cups[i]) {
                return false;
            }
        }
        for (int i = N; i < 2 * N; i++) {
            if (2 * mid > cups[i]) {
                return false;
            }
        }
        return true;
    };
    long double l = 0, r = (long double)W, ans = -1;
    while (r - l > eps) {
        long double mid = (l + r) / 2.0;
        if (f(mid)) {
            ans = mid;
            l = mid + eps;
        } else {
            r = mid - eps;
        }
    };
    cout << fixed << setprecision(12) << min((long double)W, 3 * N * ans)
         << '\n';
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
