#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    while (n--) {
        int val;
        cin >> val;
        mp[val]++;
    }
    int h = 0;
    for (auto &[a, b] : mp) {
        h = max(h, b);
    }
    cout << h << " " << mp.size() << '\n';
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
