#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N, K);
	VEC(int, A, N);
	vc<array<ll, 3>> B(N);
	FOR(i, N) {
		int mod = A[i] % K;
		if (!mod) mod = K;
		B[i] = {A[i], mod, i};
	}
	sort(all(B), [](const auto& l, const auto& r) {
		if (l[1] != r[1])
			return l[1] > r[1];
		return l[2] < r[2];
	});
	FOR(i, N) {
		fastio::wt(B[i][2] + 1);
		fastio::wt(" ");
	}
	print();
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
