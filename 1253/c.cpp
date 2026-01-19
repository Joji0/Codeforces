#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    vector<int64_t> ans(n + 1);
    sort(A.begin(), A.end());
    int64_t sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i - 1];
        ans[i] = sum;
        if (i >= m) {
            ans[i] += ans[i - m];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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
