#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> odd, even;
    for (int i = 0; i < n; i++) {
        int64_t x;
        cin >> x;
        if (x & 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    sort(odd.rbegin(), odd.rend()), sort(even.rbegin(), even.rend());
    vector<int64_t> ans(n, 0);
    if (odd.empty()) {
        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }
    if (even.empty()) {
        for (int i = 0; i < n; i += 2) {
            ans[i] = odd.front();
        }
        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }
    int ev = 0;
    int64_t best = odd.front();
    ans[0] = best;
    for (int i = 1; i < n; i++) {
        if (ev < (int)even.size()) {
            ans[i] = ans[i - 1] + even[ev];
            ev++;
        } else {
            ev--;
            ans[i] = ans[i - 2];
        }
    }
    if ((int)odd.size() % 2 == 0) {
        ans[n - 1] = 0;
    }
    for (auto &x : ans) {
        cout << x << " ";
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
