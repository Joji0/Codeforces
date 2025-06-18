#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s, ans;
    int n;
    cin >> s >> n;
    int sz = s.size();
    bool ok = false;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x.size() < s.size())
            continue;
        if (x.substr(0, sz) == s) {
            if (!ok) {
                ans = x;
                ok = true;
            } else
                ans = min(ans, x);
        }
    }
    if (!ok) {
        cout << s << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
