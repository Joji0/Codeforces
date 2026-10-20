#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	LL(A, B);
	vi ANS;
	FOR(i, 30) {
		if (((A ^ B) >> i) & 1) ANS.pb(1 << i);
	}
	for (auto& x : ANS) {
		if (x >= A) {
			print(-1);
			return;
		}
		A ^= x;
	}
	if (A != B) {
		print(-1);
		return;
	}
	print(len(ANS));
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
