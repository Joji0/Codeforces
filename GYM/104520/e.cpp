#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	vc<array<ll, 3>> ANS;
	ANS.pb({1, N + 1, 1});
	int tmp = N;
	for (int i = 2; i * i <= tmp; i++) {
		if (tmp % i == 0) {
			ANS.pb({1, N / i + 1, 0});
			while (tmp % i == 0)
				tmp /= i;
		}
	}
	if (tmp > 1) {
		ANS.pb({1, N / tmp + 1, 0});
	}
	print(len(ANS));
	for (auto& x : ANS) {
		print(x[0], x[1], x[2]);
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
