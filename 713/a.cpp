#include <bits/stdc++.h>
using namespace std;

int64_t f(int64_t x) {
    int64_t ret = 0, idx = 0;
    while (x > 0) {
        if (x & 1) {
            ret += (1LL << idx);
        }
        idx++;
        x /= 10;
    }
    return ret;
}

int64_t rev(const string &s) {
    int64_t ret = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            ret += (1LL << i);
        }
    }
    return ret;
}

void solve() {
    // idea: since |s| <= 18 think of it as a bit and just convert it to decimal
    // (save memory)
    int q;
    cin >> q;
    map<int64_t, int> mp;
    while (q--) {
        char t;
        cin >> t;
        int64_t x;
        string s;
        if (t == '+') {
            cin >> x;
            // cerr << "F(x): " << f(x) << '\n';
            mp[f(x)]++;
        } else if (t == '-') {
            cin >> x;
            // cerr << "F(x): " << f(x) << '\n';
            mp[f(x)]--;
        } else {
            cin >> s;
            reverse(s.begin(), s.end());
            // cerr << "rev(s): " << rev(s) << '\n';
            cout << mp[rev(s)] << '\n';
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
