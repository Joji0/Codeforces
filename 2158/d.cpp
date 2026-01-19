#include <bits/stdc++.h>
using namespace std;

bool ok(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void fl(string &s, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (s[i] == '1') {
            s[i] = '0';
        } else {
            s[i] = '1';
        }
    }
}

void solve() {
    // brute force
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<array<int, 2>> ans;
    while (s != t && (int)ans.size() <= 2 * n) {
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                l = i;
                break;
            }
        }
        if (l == -1)
            break;
        int r = -1;
        for (int i = n - 1; i >= l; i--) {
            if (s[i] != t[i]) {
                r = i;
                break;
            }
        }
        if (l == r) {
            cout << -1 << '\n';
            return;
        }
        int j = -1;
        for (int k = n - 1; k > l; k--) {
            if (ok(s, l, k)) {
                j = k;
                break;
            }
        }
        if (j == -1) {
            cout << -1 << '\n';
            return;
        }
        fl(s, l, j);
        ans.push_back({l + 1, j + 1});
    }
    if (s != t) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for (auto &[l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
