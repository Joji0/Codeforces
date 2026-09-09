// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/unionfind/kruskal_reconstruction_tree.hpp"
#include "ds/sparse_table/sparse_table.hpp"
#include "monoid/max.hpp"

void solve() {
        int N, M, Q; std::cin >> N >> M >> Q;
        KRT krt(N);
        std::vector<int> time(2 * N - 1);
        for (int i = 0; i < M; i++) {
                int u, v; std::cin >> u >> v; u--, v--;
                int w = krt.join(u, v);
                if (w != -1) {
                        time[w] = i;
                }
        }
        const int LOG = 21;
        std::vector<int> LCA(N - 1, 0), depth(2 * N - 1);
        std::vector<std::vector<int>> up(LOG, std::vector<int>(2 * N - 1, -1));
        auto dfs = [&](this auto &dfs, int v, int p, int d) -> void {
                depth[v] = d;
                up[0][v] = p;
                for (int i = 1; i < LOG; i++) {
                        if (up[i - 1][v] != -1) up[i][v] = up[i - 1][up[i - 1][v]];
                }
                if (krt.lc[v] != -1) dfs(krt.lc[v], v, d + 1);
                if (krt.rc[v] != -1) dfs(krt.rc[v], v, d + 1);
        };
        for (int i = 0; i < krt.nodes; i++) {
                if (krt.par[i] == -1) dfs(i, -1, 0);
        }
        auto lift = [&](int v, int k) -> int {
                for (int i = LOG - 1; i >= 0; i--) {
                        if (k >> i & 1) {
                                v = up[i][v];
                        }
                        if (v == -1) break;
                }
                return v;
        };
        auto lca = [&](int u, int v) -> int {
                if (depth[u] < depth[v]) std::swap(u, v);
                int k = depth[u] - depth[v];
                u = lift(u, k);
                if (u == v) return u;
                for (int i = LOG - 1; i >= 0; i--) {
                        if (up[i][u] != up[i][v]) {
                                u = up[i][u];
                                v = up[i][v];
                        }
                }
                return up[0][u];
        };
        for (int i = 0; i < N - 1; i++) {
                LCA[i] = time[lca(i, i + 1)];
        }
        SparseTable<MaxMonoid<int>> st(LCA);
        while (Q--) {
                int u, v; std::cin >> u >> v; u--, v--;
                if (u > v) std::swap(u, v);
                if (u == v) std::cout << "0 ";
                else std::cout << st.query(u, v - 1) + 1 << " ";
        }
        std::cout << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
