#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int i = 0, ans = 0;
    while (i < n) {
        if (s[i] == '1') {
            int cnt = 0;
            while (i < n && cnt < k) {
                i++;
                if (i < n && s[i] == '1') {
                    cnt = 0;
                    continue;
                }
                cnt++;
            }
            i++;
        } else {
            ans++;
            i++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
