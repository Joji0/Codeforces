#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int64_t> q(n), r(n);
    for (auto &x : q)
        cin >> x;
    for (auto &x : r)
        cin >> x;
    sort(q.begin(), q.end());
    multiset<int64_t> ms(r.begin(), r.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int64_t yey = (k + 1) / (q[i] + 1) - 1;
        if (yey < 1)
            continue;
        auto it = ms.upper_bound(yey);
        if (it == ms.begin())
            continue;
        --it;
        ms.erase(it);
        ans++;
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
