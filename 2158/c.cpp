#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    // kadane?
    int n, k;
    cin >> n >> k;
    vector<int64_t> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    vector<int64_t> E(n), S(n);
    E[0] = A[0];
    for (int i = 1; i < n; i++) {
        E[i] = max(A[i], E[i - 1] + A[i]);
    }
    S[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        S[i] = max(A[i], A[i] + S[i + 1]);
    }
    int64_t mx = *max_element(E.begin(), E.end());
    if (k % 2 == 0) {
        // moves just cancel out
        cout << mx << '\n';
        return;
    }
    // if odd alice get extra step
    vector<int64_t> pref(n + 1), suff(n + 1);
    pref[0] = -INF;
    for (int i = 1; i <= n; i++) {
        pref[i] = max(pref[i - 1], E[i - 1]);
    }
    suff[n] = -INF;
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = max(suff[i + 1], S[i]);
    }
    int64_t ans = -INF;
    for (int i = 0; i < n; i++) {
        int64_t curr = E[i] + S[i] - A[i] + B[i];
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
