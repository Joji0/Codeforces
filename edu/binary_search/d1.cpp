#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    cin >> k;
    sort(A.begin(), A.end());
    while (k--) {
        int64_t l, r;
        cin >> l >> r;
        auto itMin = lower_bound(A.begin(), A.end(), l),
             itMax = upper_bound(A.begin(), A.end(), r);
        if (itMax == A.begin()) {
            cout << "0 ";
        } else {
            --itMax;
            cout << (itMax - A.begin()) - (itMin - A.begin()) + 1 << ' ';
        }
    }
    cout << '\n';
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
