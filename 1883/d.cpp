#include <bits/stdc++.h>
using namespace std;

void solve() {
    multiset<int64_t> ms1, ms2;
    int q;
    cin >> q;
    while (q--) {
        char t;
        int64_t l, r;
        cin >> t >> l >> r;
        if (t == '+') {
            ms1.insert(l), ms2.insert(r);
        } else {
            ms1.erase(ms1.find(l)), ms2.erase(ms2.find(r));
        }
        if ((int)ms1.size() <= 1) {
            cout << "NO\n";
        } else if (*ms2.begin() < *ms1.rbegin()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
