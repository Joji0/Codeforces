#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

void solve() {
	INT(N, K);
	VEC(ll, A, N);
	auto Fc = cumsum<ll>(A);
	// SHOW(Fc);
	HashMap<ll> dp;
	ll ANS = 0;
	FOR(i, 1, N + 1) {
		if (i - K - 1 >= 0) {
			// if (dp[i - K - 1].count((((K - Fc[i]) % K) + K) % K) && dp[i - K - 1][(((K - Fc[i]) % K) + K) % K] > 0) {
			// 	SHOW(i);
			// 	SHOW(dp[i - K - 1][(((K - Fc[i]) % K) + K) % K]);
			// }
			// ANS += dp[i - K - 1][(((K - Fc[i]) % K) + K) % K];
			// if (dp[i - K - 1].count((((K - Fc[i]) % K) + K) % K) && dp[i - K - 1][(((K - Fc[i]) % K) + K) % K] > 0) {
			// 	SHOW(i);
			// 	SHOW(dp[i - K - 1][(((K - Fc[i]) % K) + K) % K]);
			// }
			dp[Fc[i - K - 1] % K]++;
			if (dp.count(Fc[i] % K))
				ANS += dp[Fc[i] % K];
		}
	}
	print(ANS);
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// int t = 1;
	INT(t);
	FOR(t)
	solve();

	return 0;
}
