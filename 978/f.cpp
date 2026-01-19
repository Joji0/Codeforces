#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> R(n), rem(n), sorted;
    for (auto &x : R) {
        cin >> x;
        sorted.push_back(x);
    }
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (R[u] < R[v]) {
            rem[v]++;
        } else if (R[u] > R[v]) {
            rem[u]++;
        }
    }
    sort(sorted.begin(), sorted.end());
    // cerr << "sorted: \n";
    // for (auto &x : sorted) {
    //     cerr << x << " ";
    // }
    // cerr << '\n';
    // cerr << "rem: \n";
    // for (auto &x : rem) {
    //     cerr << x << " ";
    // }
    // cerr << '\n';
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(sorted.begin(), sorted.end(), R[i]);
        // if (it == sorted.begin()) {
        //     cout << "0\n";
        // } else {
        //     --it;
        int ans = (it - sorted.begin()) - rem[i];
        cout << max(0, ans) << ' ';
        // }
    }
    cout << '\n';
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
