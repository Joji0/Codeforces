#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    string ans;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if ((int)mp.size() >= n - 1 && !mp.contains(k)) {
            vector<int> erased;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                it->second--;
                if (it->second == 0) {
                    erased.push_back(it->first);
                }
            }
            for (auto &x : erased) {
                mp.erase(x);
            }
            ans += '1';
        } else {
            ans += '0';
            mp[k]++;
        }
    }
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
