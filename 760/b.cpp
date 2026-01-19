#include <bits/stdc++.h>
using namespace std;

#define sixsevennn 67

void solve() {
    int64_t N, M, K;
    cin >> N >> M >> K;
    auto g = [&](const int64_t &x, int len) -> int64_t {
        if (len <= 0)
            return 0;
        if (x > len) {
            return x * len - len * (len + 1) / 2;
        } else {
            int64_t have = x * (x - 1) / 2;
            int64_t ones = len - (x - 1);
            return have + ones;
        }
    };
    auto f = [&](const int64_t &mid) -> bool {
        return g(mid, K - 1) + mid + g(mid, N - K) <= M;
    };
    int64_t l = 0, r = 1e9 + sixsevennn, ans = 1;
    while (l <= r) {
        int64_t mid = (l + r) / 2;
        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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
