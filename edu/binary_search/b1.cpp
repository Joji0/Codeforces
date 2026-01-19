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
        auto it = upper_bound(A.begin(), A.end(), beg);
        if (it != A.begin()) {
            cout << it - A.begin() << '\n';
        } else {
            cout << "0\n";
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
