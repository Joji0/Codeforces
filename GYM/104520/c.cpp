#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	STR(s);
	vc<int> freq(26, 0);
	FOR(i, len(s)) {
		freq[s[i] - 'a']++;
	}
	FOR_R(i, 26) {
		if (freq[i] > 0) {
			print(string(freq[i], (char)('a' + i)));
			return;
		}
	}
	assert(false);
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
