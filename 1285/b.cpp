#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    vector<int64_t> dp1(n + 1), dp2(n + 1);
    for (int i = 2; i <= n; i++) {
        dp1[i] = max(dp1[i - 1] + A[i - 1], A[i - 1]);
    }
    for (int i = 1; i <= n - 1; i++) {
        dp2[i] = max(dp2[i - 1] + A[i - 1], A[i - 1]);
    }
    int64_t g1 = *max_element(dp1.begin(), dp1.end()),
            g2 = *max_element(dp2.begin(), dp2.end()),
            s = accumulate(A.begin(), A.end(), 0LL);
    if (g1 >= s || g2 >= s) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
