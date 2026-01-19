#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int64_t> A(n), pref(n);
    for (auto &x : A)
        cin >> x;
    sort(A.rbegin(), A.rend());
    pref[0] = A[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    while (q--) {
        int64_t x;
        cin >> x;
        auto it = lower_bound(pref.begin(), pref.end(), x);
        if (it == pref.end()) {
            cout << "-1\n";
        } else {
            cout << it - pref.begin() + 1 << '\n';
        }
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
