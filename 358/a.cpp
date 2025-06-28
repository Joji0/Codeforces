#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int lleft = (a[1] >= a[0] ? a[0] : -1e6 - 5),
        lright = (a[1] <= a[0] ? a[0] : 1e6 + 5);
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
            cout << a[i + 1] << " " << lright << '\n';
            if (a[i + 1] > lright) {
                ok = false;
                break;
            } else {
                lright = a[i + 1];
                lleft = max(lleft, a[i]);
            }
        } else {
            if (a[i + 1] < lleft) {
                ok = false;
                break;
            } else {
                lleft = a[i + 1];
                lright = min(lright, a[i]);
            }
        }
    }
    cout << (!ok ? "yes\n" : "no\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
