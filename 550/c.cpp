#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    auto ok = [&](const string &t) -> bool {
        int i = 0, j = 0;
        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return (j >= (int)t.size());
    };
    for (int i = 0; i <= 992; i += 8) {
        string t = to_string(i);
        if (ok(t)) {
            cout << "YES\n" << t << '\n';
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
