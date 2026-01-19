#include <bits/stdc++.h>
using namespace std;

const int maxN = 5000069;
int spf[maxN], dp[maxN];
int64_t pref[maxN];

void hehe() {
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    for (int i = 0; i < maxN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < maxN; i++) {
        for (int64_t j = 1LL * i * i; j < maxN; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }
    for (int i = 2; i < maxN; i++) {
        dp[i] = 1 + dp[i / spf[i]];
    }
    pref[0] = 0;
    for (int i = 1; i < maxN; i++) {
        pref[i] = pref[i - 1] + dp[i];
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << pref[a] - pref[b] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    hehe();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
