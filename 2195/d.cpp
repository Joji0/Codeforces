#include <bits/stdc++.h>
using namespace std;
int n, a[1 << 20];
int64_t f[1 << 20];
void solve() {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> f[i];
        for (int i = 2; i <= n - 1; i++) {
                a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
        }
        int64_t s1 = 0, s2 = 0;
        for (int i = 1; i <= n - 1; i++) s1 += a[i] * (i - 1);
        a[n] = (f[1] - s1) / (n - 1);
        for (int i = 2; i <= n; i++) s2 += a[i];
        a[1] = f[2] - f[1] + s2;
        for (int i = 1; i <= n; i++) {
                cout << a[i] << " \n"[i == n];
        }
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        cin >> tc;
        while (tc--) solve();
        return 0;
}
