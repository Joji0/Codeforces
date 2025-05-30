#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int x;
    cin >> x;
    int y = sqrt(x);
    if (y * y == x) {
        cout << 0 << " " << y << '\n';
    } else {
        cout << "-1\n";
    }
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
