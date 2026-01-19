#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int carry = 0, ans = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
        int now = s[i] - '0';
        if (now == 0 && carry) {
            ans += 2;
        } else if (now == 0) {
            ans++;
        } else if (now == 1 && carry) {
            ans++;
        } else {
            ans += 2;
            carry = 1;
        }
    }
    if (carry)
        ans++;
    cout << ans << '\n';
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
