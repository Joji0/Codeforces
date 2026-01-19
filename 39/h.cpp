#include <bits/stdc++.h>
using namespace std;

void solve() {
    int K;
    cin >> K;
    auto conv = [&](int x) -> string {
        string ret;
        while (x > 0) {
            ret += (to_string(x % K));
            x /= K;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };
    for (int i = 1; i <= K - 1; i++) {
        for (int j = 1; j <= K - 1; j++) {
            cout << conv(i * j) << " ";
        }
        cout << '\n';
    }
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
