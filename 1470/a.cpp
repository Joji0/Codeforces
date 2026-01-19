#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> K(n), C(m);
    for (auto &x : K)
        cin >> x;
    for (auto &x : C)
        cin >> x;
    multiset<int64_t> ms(C.begin(), C.end());
    sort(K.rbegin(), K.rend());
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = ms.begin();
        if (*it >= C[K[i] - 1]) {
            ans += C[K[i] - 1];
        } else {
            ans += *it;
            ms.erase(it);
        }
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
