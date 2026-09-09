// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<std::vector<int>> T(N);
        for (int i = 0; i < N - 1; i++) {
                int u, v;
                std::cin >> u >> v; u--, v--;
                T[u].emplace_back(v);
                T[v].emplace_back(u);
        }
        int Q; std::cin >> Q;
        const int LOG = 20;
        std::vector<std::vector<int>> up(N, std::vector<int>(LOG, -1));
        std::vector<int> depth(N, 0);
        auto go = [&](this auto &go, int v, int p) -> void {
                up[v][0] = p;
                for (int i = 1; i < LOG; i++) {
                        up[v][i] = up[up[v][i - 1]][i - 1];
                }
                for (int u : T[v]) {
                        if (u == p) continue;
                        depth[u] = depth[v] + 1;
                        go(u, v);
                }
        };
        go(0, 0);
        auto lift = [&](int u, int k) -> int {
                for (int i = LOG - 1; i >= 0; i--) {
                        if (k >> i & 1) {
                                u = up[u][i];
                        }
                }
                return u;
        };
        auto lca = [&](int u, int v) -> int {
                if (depth[u] < depth[v]) std::swap(u, v);
                u = lift(u, depth[u] - depth[v]);
                if (u == v) {
                        return u;
                }
                for (int i = LOG - 1; i >= 0; i--) {
                        if (up[u][i] != up[v][i]) {
                                u = up[u][i];
                                v = up[v][i];
                        }
                }
                return up[u][0];
        };
        auto dist = [&](int u, int v) -> int {
                int LCA = lca(u, v);
                return depth[u] + depth[v] - 2 * depth[LCA];
        };
        while (Q--) {
                int a, b, c; std::cin >> a >> b >> c; a--, b--;
                if (dist(a, b) <= c) std::cout << b + 1 << '\n';
                else {
                        int LCA = lca(a, b);
                        int to_lca = depth[a] - depth[LCA];
                        if (to_lca >= c) {
                                std::cout << lift(a, c) + 1 << '\n';
                        } else {
                                c -= to_lca;
                                int rest = depth[b] - depth[LCA];
                                std::cout << lift(b, rest - c) + 1 << '\n';
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
