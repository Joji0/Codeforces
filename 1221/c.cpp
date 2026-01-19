#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;
        cout << min(min(c, m), (c + m + x) / 3) << '\n';
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
