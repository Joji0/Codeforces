#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s, ans;
    cin >> n >> s;
    int i = 0;
    while (i < n) {
        if (n % 2) {
            if (i == 3) {
                ans += '-';
            } else if ((i - 3) % 2 == 0 && i > 3) {
                ans += '-';
            }
            ans += s[i++];
        } else {
            ans += s[i++];
            if (i % 2 == 0 && i < n) {
                ans += '-';
            }
        }
    }
    cout << ans << '\n';
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
