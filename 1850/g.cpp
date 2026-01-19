#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<int64_t, int64_t> mpH, mpV, mpD, mpND;
    for (int i = 0; i < N; i++) {
        int64_t x, y;
        cin >> x >> y;
        mpH[y]++;
        mpV[x]++;
        mpD[x - y]++;
        mpND[x + y]++;
    }
    int64_t ans = 0;
    auto COMB = [&](map<int64_t, int64_t> &mp) -> void {
        for (auto &[_, cnt] : mp) {
            ans += (cnt >= 2 ? cnt * (cnt - 1) : 0);
        }
    };
    COMB(mpH), COMB(mpV), COMB(mpD), COMB(mpND);
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
