#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> mp(32, 0);
    while (N--) {
        int t;
        int64_t x;
        cin >> t >> x;
        if (t == 1) {
            mp[x]++;
        } else {
            for (int i = 31; i >= 0; i--) {
                int have = mp[i];
                while (x >= (1 << i) && have > 0) {
                    x -= (1 << i);
                    have--;
                }
            }
            if (!x) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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
