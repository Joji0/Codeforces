#include <bits/stdc++.h>
using namespace std;

void solve() {
        string s, p;
        cin >> s >> p;
        int N = (int)s.size(), M = (int)p.size();
        if (N < M) {
                cout << "0\n";
                return;
        }
        map<char, int> mp, mp_p;
        for (auto &ch : p) {
                mp_p[ch]++;
        }
        int q = 0, ans = 0;
        for (int i = 0; i < M; i++) {
                if (s[i] == '?') {
                        q++;
                } else {
                        mp[s[i]]++;
                }
        }
        auto F = [&]() -> bool {
                int diff = 0;
                for (auto &[ch, cnt] : mp) {
                        if (mp_p.contains(ch) && cnt > mp_p[ch]) {
                                return false;
                        }
                        if (!mp_p.contains(ch)) {
                                return false;
                        }
                        diff += mp_p[ch] - cnt;
                }
                return diff <= q;
        };
        if (F()) ans++;
        for (int i = M; i < N; i++) {
                if (s[i - M] != '?') {
                        mp[s[i - M]]--;
                        if (!mp[s[i - M]]) {
                                mp.erase(s[i - M]);
                        }
                } else {
                        q--;
                }
                if (s[i] != '?') {
                        mp[s[i]]++;
                } else {
                        q++;
                }
                if (F()) ans++;
        }
        cout << ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
