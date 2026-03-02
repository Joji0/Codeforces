#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        map<int, int> mp;
        for (int i = 0; i < N; i++) {
                int x;
                cin >> x;
                mp[x]++;
        }
        for (auto &[pow, cnt] : mp) {
                if (cnt >= 2) {
                        mp[pow + 1] += cnt / 2;
                        cnt %= 2;
                }
        }
        int mx = 0;
        int one = 0;
        for (auto &[pow, cnt] : mp) {
                if (cnt > 0) {
                        mx = pow;
                        one++;
                }
        }
        cout << mx + 1 - one << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
