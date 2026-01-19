#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    int cnt = 0, i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        bool bad = false;
        while (j < n && cnt <= k) {
            if (2 * A[j] > (j - 1 >= 0 ? A[j - 1] : -1)) {
                // cerr << 2 * A[j] << " " << (j - 1 >= 0 ? A[j - 1] : -1) <<
                // '\n';
                j++;
                cnt++;
            } else {
                j++;
                bad = true;
                break;
            }
        }
        // cerr << "i: " << i << " ans: " << ans << '\n';
        // cerr << "j: " << j << " cnt: " << cnt << '\n';
        if (!bad && cnt > k) {
            ans++;
            // cerr << i << " " << j << '\n';
            cnt--;
        }
        if (bad) {
            i = j - 1;
            cnt = 1;
        } else {
            i++;
        }
        // cerr << i << '\n';
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
