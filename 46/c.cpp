#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto cnt = [&](char now) -> int {
        int sz = 0;
        for (auto &ch : s) {
            if (ch == now)
                sz++;
        }
        int ret = 1e9;
        for (int i = 0; i <= n - sz; i++) {
            int curr = 0;
            for (int j = 0; j < sz; j++) {
                if (s[j + i] != now)
                    curr++;
            }
            ret = min(ret, curr);
        }
        return ret;
    };
    cout << min(cnt('H'), cnt('T')) << '\n';
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
