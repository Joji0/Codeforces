#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    vector<int64_t> fact;
    int64_t init = 6;
    for (int i = 4; i <= 15; i++) {
        fact.push_back(init);
        init *= 1LL * i;
    }
    int ans = -1;
    for (int mask = 0; mask < (1 << (int)fact.size()); mask++) {
        int64_t curr = 0;
        int one = 0;
        for (int i = 0; i < (int)fact.size(); i++) {
            if (mask & (1 << i)) {
                curr += fact[i];
                one++;
            }
        }
        if (curr > n)
            continue;
        int64_t need = n - curr;
        int cnt = __builtin_popcountll(need);
        if (ans == -1 || one + cnt < ans) {
            ans = one + cnt;
        }
    }
    cout << ans << '\n';
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
