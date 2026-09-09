// 我思う、故に我在り
#include "pch.hpp"
#include "ds/segtree/lazy_segtree.hpp"

#ifndef M1UNE_ACTED_MONOID_RANGE_FLIP_RANGE_SUM_HPP
#define M1UNE_ACTED_MONOID_RANGE_FLIP_RANGE_SUM_HPP 1

namespace m1une {
namespace acted_monoid {

struct Node {
	int c4, c7, lnds, lnis;
};

// Acted Monoid for binary arrays (0s and 1s).
// Supports range bit inversion (flip) and range sum queries.
struct ActedMonoid {
	using value_type = Node;
	using operator_type = bool;  // 'true' means flip the bits in the range
	static constexpr bool commutative = false;
	static constexpr bool operator_commutative = true;

	static constexpr value_type id() {
		return {0, 0, 0, 0};
	}

	static constexpr value_type op(const value_type& a, const value_type& b) {
		return {
		    a.c4 + b.c4,
		    a.c7 + b.c7,
		    max(a.lnds + b.c7, a.c4 + b.lnds),
		    max(a.c7 + b.lnis, a.lnis + b.c4)};
	}

	static constexpr operator_type op_id() {
		return false;
	}

	static constexpr operator_type op_comp(const operator_type& f, const operator_type& g) {
		return f ^ g;
	}

	static constexpr value_type mapping(const operator_type& f, const value_type& x) {
		if (!f) return x;
		return {x.c7, x.c4, x.lnis, x.lnds};
	}
};

}  // namespace acted_monoid
}  // namespace m1une

#endif	// M1UNE_ACTED_MONOID_RANGE_FLIP_RANGE_SUM_HPP

auto& fastin = m1une::template_io::input();
auto& fastout = m1une::template_io::output();

void solve() {
	int n, m;
	scan(n, m);
	string s;
	scan(s);
	vc<m1une::acted_monoid::Node> init(n);
	FOR(i, n) {
		if (s[i] == '4')
			init[i] = {1, 0, 1, 1};
		else
			init[i] = {0, 1, 1, 1};
	}
	m1une::ds::LazySegtree<m1une::acted_monoid::ActedMonoid> seg(init);
	FOR(m) {
		string x;
		scan(x);
		if (x == "count") {
			print(seg.all_prod().lnds);
		} else {
			int l, r;
			scan(l, r);
			l--;
			seg.apply(l, r, 1);
		}
	}
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
