#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    while (q--) {
        int64_t ask;
        cin >> ask;
        auto it = lower_bound(A.begin(), A.end(), ask);
        if (it != A.end() && *it == ask) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
