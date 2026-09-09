// 我思う、故に我在り
#include <bits/stdc++.h>
#include "math/Combinatorics.hpp"

void solve() {
        using mint = modint998;
        const int LIM = 1000005, MAXN = 2026;
        Combinatorics<mint> comb(MAXN);
        std::bitset<LIM> prime(std::string(LIM, '1'));
        prime.reset(0), prime.reset(1);
        for (int64_t i = 2; i < LIM; i++) {
                if (prime.test(i)) {
                        for (int64_t j = i * i; j < LIM; j += i) {
                                prime.reset(j);
                        }
                }
        }
        int N; std::cin >> N;
        std::vector<int> A(2 * N), freq(LIM, 0);
        int distinct_primes = 0;
        std::set<int> st;
        for (auto& x : A) {
                std::cin >> x;
                assert(x < LIM);
                if (!freq[x] && prime.test(x)) {
                        distinct_primes++;
                }
                freq[x]++;
                if (prime.test(x)) st.insert(x);
        }
        if (distinct_primes < N) {
                std::cout << "0\n";
                return;
        }
        std::vector<int> primes(st.begin(), st.end());
        int M = primes.size();
        std::vector<std::vector<mint>> dp(N + 1, std::vector<mint>(M + 1, 0));
        for (int j = 0; j <= M; j++) dp[0][j] = 1;
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] * freq[primes[j - 1]];
                }
        }
        mint ans = comb.fact(N);
        for (int i = 0; i < LIM; i++) if (freq[i] > 0) ans *= comb.inv_fact(freq[i]);
        ans *= dp[N][M];
        std::cout << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        // std::cin >> tc;
        while (tc--) solve();
        return 0;
}
