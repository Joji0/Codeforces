#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<array<int, 2>> st;
    for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        st.insert({u, v});
    }
    array<int, 2> ans = {-1, -1};
    bool found = false;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!st.contains({i, j}) && !st.contains({j, i})) {
                ans = {i, j};
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    bool win = true;
    vector<int> check;
    for (auto &[u, v] : st) {
        if (u == ans[1])
            check.push_back(v);
    }
    for (auto &c : check) {
        if (!st.contains({ans[0], c})) {
            // gabisa menang
            win = false;
            break;
        }
    }
    if (!win)
        swap(ans[0], ans[1]);
    cout << ans[0] << " " << ans[1] << '\n';
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
