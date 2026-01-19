#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<bool> mex(n, false), mn(n, false);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        for (int i = l; i <= r; i++) {
            if (t == 1)
                mn[i] = true;
            else
                mex[i] = true;
        }
    }
    vector<int> ans(n, 1e9), check;
    for (int i = 0; i < n; i++) {
        if (mn[i] && mex[i]) {
            continue;
        } else if (mn[i]) {
            ans[i] = k;
        } else if (mex[i]) {
            check.push_back(i);
        } else {
            continue;
        }
    }
    for (int i = 0; i < check.size(); i++) {
        auto idx = check[i];
        ans[idx] = i % k;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
