#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	VEC(int, A, N);
	int zero = 0, one = 0;
	for (auto& x : A) {
		if (x)
			one++;
		else
			zero++;
	}
	if (one >= zero)
		print("Bessie");
	else
		print("Elsie");
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
