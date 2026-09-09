// 我思う、故に我在り
#include "pch.hpp"

auto& fastin = m1une::template_io::input();
auto& fastout = m1une::template_io::output();

void solve() {
	ll r;
	scan(r);
	ll ans = 0;
	FOR(x, 1, r + 1) {
		ll y = floor(sqrtl((r + 1) * (r + 1) - x * x - 1));
		ll mn = 1;
		chmax(mn, ceil(sqrtl(r * r - x * x)));
		ans += max(0, y - mn + 1);
	}
	print(4 + ans * 4);
}

int main() {
	CPP_DUMP_SET_OPTION(max_line_width, 80);
	CPP_DUMP_SET_OPTION(log_label_func, cpp_dump::log_label::filename());
	CPP_DUMP_SET_OPTION(enable_asterisk, true);
	int T = 1;
	scan(T);
	while (T--) solve();
	return 0;
}
