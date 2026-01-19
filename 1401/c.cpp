#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n), cp;
    for (auto &x : A)
        cin >> x;
    cp = A;
    sort(cp.begin(), cp.end());
    int64_t mn = cp[0];
    for (int i = 0; i < n; i++) {
        if (A[i] != cp[i] && gcd(A[i], mn) != mn) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
