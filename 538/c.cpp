#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int64_t, 2>> A(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i][0] >> A[i][1];
    }
    int64_t mx1 = A[0][1] + (A[0][0] - 1),
            mx2 = A[m - 1][1] + (n - A[m - 1][0]);
    int64_t ans = max(mx1, mx2);
    bool ok = true;
    for (int i = 0; i < m - 1; i++) {
        if (abs(A[i + 1][1] - A[i][1]) > A[i + 1][0] - A[i][0]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if (m == 1) {
        cout << ans << '\n';
        return;
    }
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, max(A[i + 1][1], A[i][1]) +
                           (int64_t)floor((A[i + 1][0] - A[i][0] -
                                           max(A[i + 1][1], A[i][1]) +
                                           min(A[i + 1][1], A[i][1])) /
                                          2.0));
    }
    cout << ans << '\n';
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
/*
 * 7 8 9 10 11 12
 * 5 6 7 8 7 6
 *
 * 7 8 9 10 11 12
 * 5 6 6 5 4 3
 *
 * 7 8 9 10 11 12
 * 5 6 5 4 3 2
 *
 * 7 8 9 10 11 12
 * 5 5 4 3 2 1
 *
 * 7 8 9 10 11 12 13
 * 5 4 3 2 1 0 -1
 */
