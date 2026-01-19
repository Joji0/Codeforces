#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    int ans = a, now = a;
    for (int i = 0; i < maxN; i++) {
        now = (a + i * b) % l;
        ans = max(ans, now);
    }
    cout << ans << '\n';
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
