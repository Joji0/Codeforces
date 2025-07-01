#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x <= c / a; x++) {
        int r = c - x * a;
        if (r % b == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
