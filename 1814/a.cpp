#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k % 2 == 0 && n % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
