#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    vector<int> pref(n), suff(n);
    pref[0] = A[0];
    suff[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + A[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (pref[i] == suff[i + 1]);
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
