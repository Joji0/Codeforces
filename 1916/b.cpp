#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    if (g == 1) {
        cout << a * b << '\n';
    }
    int l = lcm(a / g, b / g);
    cout << max(a, b) * l / g << '\n';
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
