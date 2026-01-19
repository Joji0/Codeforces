#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26, 0);
    for (auto &x : t) {
        cnt[x - 'a']++;
    }
    for (auto &x : s) {
        cnt[x - 'a']--;
        if (cnt[x - 'a'] < 0) {
            cout << "Impossible\n";
            return;
        }
    }
    string res;
    for (char c : s) {
        for (int j = 0; j < (c - 'a'); j++) {
            if (cnt[j] > 0) {
                res += string(cnt[j], 'a' + j);
                cnt[j] = 0;
            }
        }
        res += c;
    }
    for (int j = 0; j < 26; j++) {
        if (cnt[j] > 0) {
            res += string(cnt[j], 'a' + j);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
