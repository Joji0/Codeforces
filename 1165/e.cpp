#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    sort(B.begin(), B.end());
    for (int i = 1; i <= n; i++) {
        A[i - 1] = A[i - 1] * i * (n - i + 1);
    }
    sort(A.rbegin(), A.rend());
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((A[i] % MOD) * (B[i] % MOD)) % MOD;
    }
    cout << ans % MOD << '\n';
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
