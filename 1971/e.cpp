// 我思う、故に我在り
#include "pch.hpp"

auto& fastin = m1une::template_io::input();
auto& fastout = m1une::template_io::output();

void solve() {
	ll n, k, q;
	scan(n, k, q);
	vl a(k + 1), b(k + 1);
	FOR(i, 1, k + 1)
	scan(a[i]);
	FOR(i, 1, k + 1)
	scan(b[i]);
	a[0] = 0;
	b[0] = 0;
	FOR(q) {
		ll d;
		scan(d);
		if (d == 0) {
			fastout.write("0 ");
			continue;
		}
		auto it = lower_bound(all(a), d);
		auto prv = prev(it);
		ll j = it - a.begin(), i = prv - a.begin();
		ll ans = (ll)(b[i]) + (1LL) * (d - a[i]) * (ll)(b[j] - b[i]) / (a[j] - a[i]);
		// dump(d - a[i]);
		// dump(a[j] - a[i]);
		// dump(b[j] - b[i]);
		fastout.write(ans);
		fastout.write(" ");
	}
	print();
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
