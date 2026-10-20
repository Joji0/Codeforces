#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(Q);
	FOR(Q) {
		LL(l, r, x);
		ll half = x >> 1;
		if ((x & 1) || half < l || half > r) {
			print(0);
		} else {
			print(half - l + 1);
		}
	}
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
