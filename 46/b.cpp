#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> N(5);
    for (auto &x : N)
        cin >> x;
    map<string, int> mp = {{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}};
    map<int, string> back;
    for (auto &[x, y] : mp) {
        back[y] = x;
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int l = -1, r = -1;
        for (int i = mp[s]; i < 5; i++) {
            if (N[i]) {
                r = i;
                break;
            }
        }
        for (int i = mp[s]; i >= 0; i--) {
            if (N[i]) {
                l = i;
                break;
            }
        }
        if (l != -1 && r != -1) {
            if (abs(mp[s] - l) == abs(mp[s] - r)) {
                cout << back[r] << '\n';
                N[r]--;
            } else {
                cout << back[(abs(mp[s] - l) < abs(mp[s] - r) ? l : r)] << '\n';
                if (abs(mp[s] - l) < abs(mp[s] - r)) {
                    N[l]--;
                } else {
                    N[r]--;
                }
            }
        } else if (l != -1) {
            cout << back[l] << '\n';
            N[l]--;
        } else {
            cout << back[r] << '\n';
            N[r]--;
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
