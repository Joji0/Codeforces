#include <bits/stdc++.h>
using namespace std;
int n, a[1 << 20];
int go(int x) {
        while (!(x & 1)) {
                x /= 2;
        }
        return x;
}
void solve() {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        bool ok = true;
        for (int i = 1; i <= n; i++) {
                ok &= (go(a[i]) == go(i));
        }
        cout << (ok ? "YES\n" : "NO\n");
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        cin >> tc;
        while (tc--) solve();
        return 0;
}
