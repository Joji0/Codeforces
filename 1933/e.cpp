#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> S(n);
    for (auto &x : S)
        cin >> x;
    vector<int64_t> pref(n);
    pref[0] = S[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + S[i];
    }
    auto comp = [&](int64_t u, int64_t val) -> int64_t {
        return u * val - ((val - 1) * val) / 2;
    };
    int q;
    cin >> q;
    while (q--) {
        int l;
        int64_t u;
        cin >> l >> u;
        l--;
        int64_t base = (l ? pref[l - 1] : 0);
        int r = n - 1;
        int64_t best = comp(u, pref[l] - base);
        auto it = upper_bound(pref.begin() + l, pref.end(), base + u);
        int idx = it - pref.begin();
        if (idx - 1 >= l) {
            int64_t val = comp(u, pref[idx - 1] - base);
            if (val > best || (val == best && idx - 1 < r)) {
                best = val;
                r = idx - 1;
            }
        }
        if (idx < n) {
            int64_t val = comp(u, pref[idx] - base);
            if (val > best || (val == best && idx < r)) {
                best = val;
                r = idx;
            }
        }
        cout << r + 1 << " ";
    }
    cout << '\n';
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
