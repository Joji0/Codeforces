#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	INT(N);
	STR(s);
	int cnt = count(all(s), '1');
	if (cnt == 2) {
		print(1);
		return;
	}
	int l = 0, r = N - 1;
	while (s[l] != '1') l++;
	while (s[r] != '1') r--;
	print(r - l);
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
