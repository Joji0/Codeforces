#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N, K);
	multiset<ll> ms;
	FOR(N) {
		LL(x);
		ms.insert(x);
	}
	FOR(K) {
		ll f = *ms.begin();
		ms.erase(ms.begin());
		ms.insert(f + 1);
	}
	print(*ms.begin());
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
