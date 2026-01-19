#include <bits/stdc++.h>
using namespace std;

void solve() {
    string ans;
    int n;
    cin >> n;
    vector<string> opt(n);
    for (auto &x : opt)
        cin >> x;
    for (int i = 0; i < n; i++) {
        string opt1 = ans + opt[i], opt2 = opt[i] + ans;
        ans = min(opt1, opt2);
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
