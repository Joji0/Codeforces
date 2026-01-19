#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int64_t, int> mp;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        mp[v]++;
    }
    int m;
    cin >> m;
    vector<int64_t> B(m), C(m);
    for (auto &x : B)
        cin >> x;
    for (auto &x : C)
        cin >> x;
    vector<array<int64_t, 3>> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back({i + 1, mp[B[i]], mp[C[i]]});
    }
    sort(ans.begin(), ans.end(), [](const auto &a, const auto &b) {
        if (a[1] == b[1]) {
            return a[2] > b[2];
        }
        return a[1] > b[1];
    });
    cout << ans[0][0] << '\n';
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
