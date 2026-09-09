// 我思う、故に我在り
#include "pch.hpp"

auto& fastin = m1une::template_io::input();
auto& fastout = m1une::template_io::output();

void solve() {
	int n;
	scan(n);
	vi a(n);
	scan(a);
	FOR_R(i, 31) {
		int cnt = 0, who = -1;
		FOR(j, n) {
			if (a[j] >> i & 1) {
				cnt++;
				who = j;
			}
		}
		if (cnt == 1) {
			print(a[who]);
			FOR(j, n) {
				if (j == who) continue;
				print(a[j]);
			}
			return;
		}
	}
	print(a);
}

int main() {
	CPP_DUMP_SET_OPTION(max_line_width, 80);
	CPP_DUMP_SET_OPTION(log_label_func, cpp_dump::log_label::filename());
	CPP_DUMP_SET_OPTION(enable_asterisk, true);
	int T = 1;
	// scan(T);
	while (T--) solve();
	return 0;
}
