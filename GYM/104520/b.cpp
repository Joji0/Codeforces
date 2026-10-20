#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	VEC(int, A, N);
	int ex = 1;
	FOR(i, N) {
		if (A[i] != ex) {
			print(N - i);
			return;
		}
		++ex;
	}
	print(0);
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
