#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    string s;
    cin >> N >> s;
    if ((int)s.size() < 2) {
        cout << "-1\n";
        return;
    }
    vector<int> ans, pref1(N), suff1(N);
    vector<vector<int>> pref2(N, vector<int>(26, 0)),
        suff2(N, vector<int>(26, 0));
    set<char> st1, st2;
    for (int i = 0; i < N; i++) {
        st1.insert(s[i]);
        pref1[i] = st1.size();
    }
    for (int i = N - 1; i >= 0; i--) {
        st2.insert(s[i]);
        suff1[i] = st2.size();
    }
    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < N; i++) {
            pref2[i][j] = (i ? pref2[i - 1][j] : 0) + (s[i] - 'a' == j);
        }
    }
    for (int j = 0; j < 26; j++) {
        for (int i = N - 1; i >= 0; i--) {
            suff2[i][j] = (i < N - 1 ? suff2[i + 1][j] : 0) + (s[i] - 'a' == j);
        }
    }
    for (int i = 0; i < N - 1; i++) {
        if (pref1[i] == suff1[i + 1]) {
            set<char> check;
            int mx1 = *max_element(pref2[i].begin(), pref2[i].end()),
                mx2 = *max_element(suff2[i + 1].begin(), suff2[i + 1].end());
            for (int j = 0; j < 26; j++) {
                if (pref2[i][j] == mx1) {
                    check.insert(j);
                }
            }
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                if (suff2[i + 1][j] == mx2 && check.contains(j)) {
                    ok = false;
                }
            }
            if (ok)
                ans.push_back(i);
        }
    }
    if ((int)ans.size() == 0) {
        cout << "-1\n";
    } else {
        for (auto &x : ans) {
            cout << x + 1 << " ";
        }
        cout << '\n';
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
