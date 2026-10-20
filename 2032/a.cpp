#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	VEC(int, A, 2 * N);
	int cnt[2] = {0, 0};
	FOR(i, 2 * N) { cnt[A[i]]++; }
	if (cnt[0] & 1)
		print(1);
	else
		print(0);
	print(min(cnt[0], cnt[1]));
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
