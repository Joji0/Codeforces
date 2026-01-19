#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    while (k--) {
        int64_t beg;
        cin >> beg;
        auto it = lower_bound(A.begin(), A.end(), beg);
        if (it != A.end()) {
            cout << it - A.begin() + 1 << '\n';
        } else {
            cout << n + 1 << '\n';
        }
    }
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
