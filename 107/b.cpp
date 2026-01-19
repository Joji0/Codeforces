#include <bits/stdc++.h>
using namespace std;

using ld = long double;

ld comb(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    k = min(k, n - k);
    ld ret = 1;
    for (int i = 1; i <= k; i++) {
        ret *= (n - k + i);
        ret /= i;
    }
    return ret;
}

void solve() {
    int N, M, H;
    cin >> N >> M >> H;
    vector<int> S(M + 1);
    int tot = 0;
    for (int i = 1; i <= M; i++) {
        cin >> S[i];
        tot += S[i];
    }
    if (tot < N) {
        cout << "-1\n";
        return;
    }
    if (N == 1) {
        cout << "0\n";
        return;
    }
    int dept = S[H] - 1, other = tot - S[H];
    ld ans = 0;
    for (int i = 1; i <= min(dept, N - 1); i++) {
        ans += comb(dept, i) * comb(other, N - 1 - i) / comb(tot - 1, N - 1);
    }
    cout << fixed << setprecision(12) << ans << '\n';
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
