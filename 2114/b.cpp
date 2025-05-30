#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int o = 0, z = 0, n, k;
    string s;
    cin >> n >> k >> s;
    for (auto &ch : s) {
        if (ch - '0')
            o++;
        else
            z++;
    }
    bool flag = false;
    if ((max(o, z) - n / 2 <= k) && !((k - max(o, z) + n / 2) % 2) &&
        (o / 2 + z / 2 >= k)) {
        flag = true;
    }
    cout << (flag ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
