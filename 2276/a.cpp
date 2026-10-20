#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(A, B);
	if (B >= A) {
		print(-1);
		return;
	}
	print(min({A >> 1, B, A - B}));
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
