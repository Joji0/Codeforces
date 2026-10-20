#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
	string s;
	read(s);
	int x = 0, y = 0;
	FOR(i, 1, len(s) - 1) {
		if (s[i - 1] == s[i + 1]) {
			if (s[i] != s[i - 1] && x > 0) continue;
			if (s[i] != s[i - 1])
				x++;
			else
				y++;
		}
	}
	print(bool(x) + bool(y) + 1);
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
