#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N, M);
	VEC(ll, S, N);
	VEC(ll, A, M);
	sort(all(S)), sort(all(A));
	int l = 0, r = 0, ANS = 0;
	while (l < M && r < N) {
		while (r < N && S[r] < A[l]) {
			r++;
		}
		if (r < N && S[r] >= A[l]) {
			r++;
			ANS++;
		}
		l++;
	}
	print(ANS);
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t = 1;
	// INT(t);
	FOR(t)
	solve();

	return 0;
}
