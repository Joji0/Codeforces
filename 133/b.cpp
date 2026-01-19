#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;

int64_t binexp(int64_t a, int64_t b, int64_t MOD) {
    a %= MOD;
    int64_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    auto gimme = [](const string &s) -> string {
        map<char, string> mp = {{'>', "1000"}, {'<', "1001"}, {'+', "1010"},
                                {'-', "1011"}, {'.', "1100"}, {',', "1101"},
                                {'[', "1110"}, {']', "1111"}};
        string ret;
        for (auto &ch : s) {
            ret += mp[ch];
        }
        return ret;
    };
    string conv = gimme(s);
    auto ans = [&](string &x) -> int64_t {
        reverse(x.begin(), x.end());
        int p = 0;
        int64_t ret = 0;
        for (auto &ch : x) {
            if (ch - '0') {
                ret += binexp(2, p, MOD);
                ret %= MOD;
            }
            p++;
        }
        return ret;
    };
    cout << ans(conv) % MOD << '\n';
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
