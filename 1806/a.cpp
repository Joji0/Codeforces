#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b) {
        cout << "-1\n";
        return;
    }
    ll dif = d - b;
    if (a + dif < c) {
        cout << "-1\n";
        return;
    }
    cout << 2 * dif + a - c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
