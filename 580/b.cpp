#include <bits/stdc++.h>
using namespace std;

struct Info {
    int64_t m, s;
};

void solve() {
    int n;
    int64_t d;
    cin >> n >> d;
    vector<Info> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].m >> A[i].s;
    }
    sort(A.begin(), A.end(),
         [](const auto &a, const auto &b) { return a.m < b.m; });
    int64_t ans = 0, curr = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        while (l < r && A[r].m - A[l].m >= d) {
            curr -= A[l].s;
            l++;
        }
        curr += A[r].s;
        ans = max(ans, curr);
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
