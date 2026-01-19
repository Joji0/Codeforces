#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int jump = 1; jump < n; jump++) {
        bool ok = false;
        for (int start = 0; start < n; start++) {
            if (s[start] == '.')
                continue;
            int cnt = 0;
            for (int shift = 1; shift <= 4; shift++) {
                if (start + shift * jump < n &&
                    s[start + shift * jump] != '.') {
                    cnt++;
                }
            }
            if (cnt >= 4) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
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
