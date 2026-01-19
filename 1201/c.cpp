#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    auto f = [&](int64_t mid) -> bool {
        int64_t cnt = 0;
        for (int i = n / 2; i < n; i++) {
            cnt += max(0LL, mid - A[i]);
            if (cnt > k) {
                return false;
            }
        }
        return cnt <= k;
    };
    sort(A.begin(), A.end());
    int64_t l = A[n / 2], r = 1e15, ans = l;
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
