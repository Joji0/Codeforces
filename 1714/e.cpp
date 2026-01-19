#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (A[i] % 10 == 0 || A[i] % 10 == 5) {
            ok = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ok && (A[i] % 10 != 0 && A[i] % 10 != 5)) {
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
