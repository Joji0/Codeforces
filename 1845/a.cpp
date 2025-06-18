#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if ((k == x && x == 1)) {
        cout << "NO\n";
        return;
    }
    if (x == 1) {
        if (n & 1) {
            if (k < 3) {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
            cout << 1 + (n - 3) / 2 << '\n';
            cout << "3 ";
            for (int i = 0; i < (n - 3) / 2; i++) {
                cout << 2 << " ";
            }
            cout << '\n';
        } else {
            cout << "YES\n";
            cout << n / 2 << '\n';
            for (int i = 0; i < n / 2; i++) {
                cout << 2 << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "YES\n";
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << " \n"[i == n - 1];
        }
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
