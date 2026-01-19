#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    auto gimme = [](const int &x) -> vector<int> {
        vector<int> ret;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ret.push_back(i);
                if (x % (x / i) == 0 && i != x / i) {
                    ret.push_back(x / i);
                }
            }
        }
        return ret;
    };
    vector<int> dn = gimme(n), dm = gimme(m);
    set<string> ddn, ddm;
    auto solver = [](const string &s, set<string> &st,
                     const vector<int> &divs) {
        for (auto &x : divs) {
            string temp, got;
            for (int i = 0; i < x; i++) {
                temp += s[i];
            }
            for (int i = 0; i < (int)s.size() / x; i++) {
                got += temp;
            }
            if (got == s) {
                st.insert(temp);
            }
        }
    };
    solver(s, ddn, dn);
    solver(t, ddm, dm);
    set<string> ans;
    for (auto &x : ddn) {
        if (ddm.contains(x)) {
            ans.insert(x);
        }
    }
    // cerr << "DEBUG DDN: \n";
    // for (auto &x : ddn) {
    //     cerr << x << '\n';
    // }
    // cerr << "DEBUG DDM: \n";
    // for (auto &x : ddm) {
    //     cerr << x << '\n';
    // }
    cout << (int)ans.size() << '\n';
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
