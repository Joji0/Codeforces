#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    int64_t dp1 = 0, dp2 = -INF;
    for (int i = n - 1; i >= 0; i--) {
        int64_t ndp1 = max(dp1 - A[i], dp2 - B[i]);
        int64_t ndp2 = max(dp2 + A[i], dp1 + B[i]);
        dp1 = ndp1;
        dp2 = ndp2;
    }
    cout << max(dp1, dp2) << '\n';
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
