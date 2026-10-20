#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	VEC(ll, A, N);
	vc<ll> P(N + 1, 0), S(N + 2, 0);
	FOR(i, 1, N + 1) {
		P[i] = P[i - 1] + (A[i - 1] > 0 ? A[i - 1] : 0);
	}
	FOR_R(i, 1, N + 1) {
		S[i] = S[i + 1] + (A[i - 1] < 0 ? -A[i - 1] : 0);
	}
	ll ANS = 0;
	FOR(i, 1, N + 1) {
		chmax(ANS, P[i] + S[i]);
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
