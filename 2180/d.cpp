#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<int64_t> D(n - 1);
    for (int i = 0; i < n - 1; i++) {
        D[i] = A[i + 1] - A[i];
    }
    int64_t ans = 0;
    int l = 0;
    while (l < n) {
        int64_t L = 0, U = INF, B = 0;
        int best_r = l;
        for (int r = l + 1; r < n; r++) {
            int k = r - l;
            if (k % 2 == 1) {
                B += D[r - 1];
                U = min(U, B);
            } else {
                B -= D[r - 1];
                L = max(L, B);
            }
            if (L >= U)
                break;
            int64_t mn;
            if (k % 2 == 0) {
                mn = L - B;
            } else {
                mn = B - U;
            }
            if (r < n - 1 && mn >= D[r]) {
                continue;
            }
            best_r = r;
        }
        ans += best_r - l;
        l = best_r + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
