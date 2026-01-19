#include <bits/stdc++.h>
using namespace std;

string conv(int64_t x) {
    string ret;
    for (int i = 0; i < 63; i++) {
        ret += (((1ll << i) & x) ? 1 : 0) + '0';
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    int64_t l, r;
    cin >> l >> r;
    if (l == r) {
        cout << "0\n";
        return;
    }
    string ls = conv(l), rs = conv(r);
    int i = 0;
    while (ls[i] == rs[i]) {
        i++;
    }
    cout << (1ull << (63 - i)) - 1 << '\n';
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
