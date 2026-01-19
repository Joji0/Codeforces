#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    int64_t mx = A[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < mx) {
            int64_t diff = mx - A[i], msb = -1;
            for (int j = 35; j >= 0; j--) {
                if ((1LL << j) & diff) {
                    msb = j;
                    break;
                }
            }
            assert(msb != -1);
            ans = max(ans, msb + 1);
            A[i] = mx;
        }
        mx = max(mx, A[i]);
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
