#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int q;
    cin >> s >> q;
    int n = (int)s.size();
    vector<int> prefx(n), prefy(n), prefz(n);
    prefx[0] = s[0] == 'x';
    prefy[0] = s[0] == 'y';
    prefz[0] = s[0] == 'z';
    for (int i = 1; i < n; i++) {
        prefx[i] = prefx[i - 1] + (s[i] == 'x');
        prefy[i] = prefy[i - 1] + (s[i] == 'y');
        prefz[i] = prefz[i - 1] + (s[i] == 'z');
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (r - l <= 1) {
            cout << "YES\n";
            continue;
        }
        int xx = prefx[r] - (l ? prefx[l - 1] : 0);
        int yy = prefy[r] - (l ? prefy[l - 1] : 0);
        int zz = prefz[r] - (l ? prefz[l - 1] : 0);
        int mx = max({xx, yy, zz}), mn = min({xx, yy, zz});
        if (mx - mn <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
