#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<array<int, 3>> check;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        check.push_back({u, v, i});
        check.push_back({v, u, i});
    }
    auto f = [](int a, int b, int u1, int v1, int u2, int v2) -> int {
        int acop = a, bcop = b;
        acop -= u1, bcop -= v1;
        bool ok = false;
        if (u2 <= acop && v2 <= b) {
            ok = true;
        }
        if (u2 <= a && v2 <= bcop) {
            ok = true;
        }
        if (acop < 0 || bcop < 0)
            ok = false;
        return (ok ? (u1 * v1 + u2 * v2) : -1);
    };
    int ans = 0;
    for (auto &[u1, v1, id1] : check) {
        for (auto &[u2, v2, id2] : check) {
            if (id1 == id2)
                continue;
            ans = max(ans, f(a, b, u1, v1, u2, v2));
            ans = max(ans, f(b, a, u1, v1, u2, v2));
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
