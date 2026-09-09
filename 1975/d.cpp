// 我思う、故に我在り
#include "template.hpp"
#include "graph/tree/rooted_tree.hpp"
#include "graph/shortest_path.hpp"

auto& fastin = m1une::template_io::input();
auto& fastout = m1une::template_io::output();

void solve() {
	int n, a, b;
	scan(n, a, b);
	a--, b--;
	m1une::graph::Graph<ll> G(n);
	FOR(n - 1) {
		int u, v;
		scan(u, v);
		u--, v--;
		G.add_edge(u, v);
	}
	m1une::tree::RootedTree<ll> T(G, a);
	int dab = T.dist_edges(a, b);
	int r = T.jump(a, b, dab / 2);
	m1une::tree::RootedTree<ll> Tr(G, r);
	auto res = m1une::graph::zero_one_bfs(G, r).dist;
	print((dab + 1) / 2 + 2 * (n - 1) - *max_element(all(res)));
}

int main() {
	// CPP_DUMP_SET_OPTION(max_line_width, 80);
	// CPP_DUMP_SET_OPTION(log_label_func, cpp_dump::log_label::filename());
	// CPP_DUMP_SET_OPTION(enable_asterisk, true);
	int T = 1;
	scan(T);
	while (T--) solve();
	return 0;
}
