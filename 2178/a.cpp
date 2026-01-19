#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int y = 0;
    for (auto &ch : s) {
        if (ch == 'Y')
            y++;
    }
    cout << (y > 1 ? "NO\n" : "YES\n");
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
