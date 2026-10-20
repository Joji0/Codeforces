#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	VEC(ll, A, N);
	vvv(ll, dp, N + 1, 2, 2);
	FOR(i, 1, N + 1) {
		FOR(j, 2) {
			FOR(k, 2) {
				if (j == 0) {
					dp[i][0][j] = max({dp[i][0][j], dp[i - 1][0][k] + A[i - 1], dp[i - 1][1][k] + A[i - 1]});
				} else {
					dp[i][0][j] = max({dp[i][0][j], dp[i - 1][0][k] * A[i - 1], dp[i - 1][1][k] * A[i - 1]});
				}
			}
		}
		FOR(j, 2) {
			FOR(k, 2) {
				if (j == 0) {
					dp[i][1][j] = min({dp[i][1][j], dp[i - 1][0][k] + A[i - 1], dp[i - 1][1][k] + A[i - 1]});
				} else {
					dp[i][1][j] = min({dp[i][1][j], dp[i - 1][0][k] * A[i - 1], dp[i - 1][1][k] * A[i - 1]});
				}
			}
		}
	}
	ll ANS = -infty<ll>;
	FOR(i, 2) {
		FOR(j, 2) {
			chmax(ANS, dp[N][i][j]);
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
