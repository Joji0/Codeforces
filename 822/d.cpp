#include "mod/modint.hpp"
#include "nt/sieve.hpp"
#include <bits/stdc++.h>
using namespace std;
constexpr int maxR = 5000001;
using Mint = ModInt<1000000007>;

void solve() {
        NT::Sieve sieve(maxR);
        Mint T;
        int L, R;
        cin >> T >> L >> R;
        vector<Mint> T_pow(maxR, 0), dp(maxR, 0);
        T_pow[0] = Mint(1);
        for (int i = 1; i < maxR; i++) {
                T_pow[i] = T_pow[i - 1] * T;
        }
        for (int i = 2; i < maxR; i++) {
                int spf = sieve.spf[i];
                dp[i] = dp[i / spf] + (Mint(i) * (spf - 1) / 2);
        }
        Mint ans = 0;
        for (int i = L; i <= R; i++) {
                ans += T_pow[i - L] * dp[i];
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
