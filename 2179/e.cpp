#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t N, X, Y;
    string s;
    cin >> N >> X >> Y >> s;
    int64_t cnt0 = 0, cnt1 = 0, mn0 = 0, mn1 = 0, lsum = 0;
    for (int i = 0; i < N; i++) {
        int64_t p;
        cin >> p;
        int64_t winner = (p + 2) / 2;
        int64_t loser = p - winner;
        lsum += loser;
        if (s[i] == '0') {
            cnt0++;
            mn0 += winner;
            mn1 += loser;
        } else {
            cnt1++;
            mn1 += winner;
            mn0 += loser;
        }
    }
    bool ok = true;
    ok &= (X >= mn0);
    ok &= (Y >= mn1);
    ok &= (X >= lsum + cnt0);
    ok &= (Y >= lsum + cnt1);
    if (cnt0 == 0 && cnt1 > 0)
        ok &= (Y >= X + cnt1);
    if (cnt1 == 0 && cnt0 > 0)
        ok &= (X >= Y + cnt0);
    cout << (ok ? "YES" : "NO") << '\n';
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
