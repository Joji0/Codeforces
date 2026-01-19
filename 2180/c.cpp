#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " \n"[i == k - 1];
        }
    } else {
        // not trivial case
        // cout << "0 ";
        // for (int i = 0; i < k - 1; i++) {
        //     cout << n << " ";
        // }
        // cout << '\n';
        int64_t a, b;
        if ((n & (n - 1)) == 0) {
            a = n;
            b = 0;
        } else {
            int msb = 0;
            for (int i = 60; i >= 0; i--) {
                if ((1LL << i) & n) {
                    msb = i;
                    break;
                }
            }
            int64_t L = n ^ (1LL << msb);
            int h = 63 - __builtin_clzll(L);
            a = (n ^ (1LL << h)) | ((1LL << h) - 1);
            b = a ^ n;
        }
        cout << a << " " << b << " ";
        for (int i = 2; i < k; i++) {
            cout << n << " ";
        }
        cout << '\n';
    }
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
