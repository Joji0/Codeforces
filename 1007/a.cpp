#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    multiset<int> ms;
    for (auto &x : A) {
        cin >> x;
        ms.insert(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(A[i]);
        if (it == ms.end()) {
            continue;
        } else {
            ans++;
            ms.erase(it);
        }
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
