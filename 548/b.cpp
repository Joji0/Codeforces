#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> ans(n, 0);
    auto comp = [&](int row) -> int {
        int ret = 0, curr = 0;
        for (int j = 0; j < m; j++) {
            if (g[row][j]) {
                curr++;
            } else {
                curr = 0;
            }
            ret = max(ret, curr);
        }
        return ret;
    };
    for (int i = 0; i < n; i++) {
        ans[i] = comp(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        g[x - 1][y - 1] ^= 1;
        ans[x - 1] = comp(x - 1);
        cout << *max_element(ans.begin(), ans.end()) << '\n';
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
