#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    if (mp.size() > 2) {
        cout << "No\n";
    } else if (mp.size() == 2) {
        bool found = false;
        for (auto &[k, v] : mp) {
            if (v == n / 2)
                found = true;
        }
        if (!found) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    } else {
        cout << "Yes\n";
    }
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
