#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool almostPrime(int x) {
    int cnt = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            cnt++;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        cnt++;
    }
    return cnt == 2;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (almostPrime(i))
            ans++;
    }
    cout << ans << '\n';
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
