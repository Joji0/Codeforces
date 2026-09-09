// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/add.hpp"

void solve() {
        int N; std::cin >> N;
        std::vector<std::vector<int>> T(N);
        std::vector<int> tin(N), tout(N);
        for (int i = 0; i < N - 1; i++) {
                int u, v; std::cin >> u >> v; u--, v--;
                T[u].emplace_back(v);
                T[v].emplace_back(u);
        }
        int timer = 0;
        auto dfs = [&](this auto &dfs, int v, int p) -> void {
                tin[v] = timer++;
                for (int u : T[v]) {
                        if (u == p) continue;
                        dfs(u, v);
                }
                tout[v] = timer;
        };
        dfs(0, -1);
        SegTree<AddMonoid<double>> seg(N);
        int Q; std::cin >> Q;
        while (Q--) {
                int t, x, y; std::cin >> t >> x >> y; x--, y--;
                if (t == 1) {
                        y++;
                        seg.update(tin[x], log10(y));
                } else {
                        double sub1 = seg.query(tin[x], tout[x] - 1);
                        double sub2 = seg.query(tin[y], tout[y] - 1);
                        if (sub1 - sub2 > 9.0) {
                                std::cout << 1000000000 << '\n';
                        } else {
                                std::cout << std::fixed << std::setprecision(10) << pow(10, sub1 - sub2) << '\n';
                        }
                }
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
