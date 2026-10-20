#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N, K);
	if (N == 1) {
		print(1);
		print(1);
		return;
	}
	if (K == 1 || K == N) {
		print(-1);
	} else {
		if (K & 1) {
			print(3);
			print(1, K - 1, K + 2);
		} else {
			print(3);
			print(1, K, K + 1);
		}
	}
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
