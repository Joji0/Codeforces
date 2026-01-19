#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    for (int64_t a = 0; a < 1000; a++) {
        if (a * 1234567 > n)
            break;
        for (int64_t b = 0; b < 10000; b++) {
            if (a * 1234567 + b * 123456 > n)
                break;
            int64_t c = n - a * 1234567 - b * 123456;
            if (c % 1234 == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
