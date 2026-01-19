#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t N;
    cin >> N;
    auto f = [&]() -> set<int64_t> {
        set<int64_t> ret;
        for (int64_t i = 1; i * (i + 1) <= 2 * N; i++) {
            ret.insert(i * (i + 1) / 2);
        }
        return ret;
    };
    set<int64_t> g = f();
    for (auto &x : g) {
        int64_t need = N - x;
        if (g.contains(need)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
