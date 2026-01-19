#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b;
    cin >> a >> b;
    set<int64_t> d, ad, bd;
    auto prec = [](int64_t x, set<int64_t> &xd) {
        for (int64_t i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                xd.insert(i);
                if (x % (x / i) == 0 && i != x / i) {
                    xd.insert(x / i);
                }
            }
        }
    };
    prec(a, ad), prec(b, bd);
    for (auto &x : ad) {
        if (bd.contains(x)) {
            d.insert(x);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int64_t l, r;
        cin >> l >> r;
        auto it = d.upper_bound(r);
        if (it == d.begin()) {
            cout << "-1\n";
            continue;
        }
        it--;
        if (*it >= l) {
            cout << *it << '\n';
        } else {
            cout << "-1\n";
        }
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
