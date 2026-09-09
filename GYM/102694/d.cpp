// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        const int LOG = 20;
        std::vector<std::vector<std::pair<int, int>>> T(N);
        std::vector<std::vector<int>> up(N, std::vector<int>(LOG, 0)), flow(N, std::vector<int>(LOG, std::numeric_limits<int>::max()));
        std::vector<int> depth(N, 0);
        for (int i = 0; i < M; i++) {
                int u, v, w; std::cin >> u >> v >> w; u--, v--;
                T[u].emplace_back(v, w);
                T[v].emplace_back(u, w);
        }
        auto dfs = [&](this auto &dfs, int v, int p, int w) -> void {
                up[v][0] = p;
                flow[v][0] = w;
                for (int i = 1; i < LOG; i++) {
                        up[v][i] = up[up[v][i - 1]][i - 1];
                        flow[v][i] = std::min(flow[v][i - 1], flow[up[v][i - 1]][i - 1]);
                }
                for (auto &[u, w] : T[v]) {
                        if (u == p) continue;
                        depth[u] = depth[v] + 1;
                        dfs(u, v, w);
                }
        };
        dfs(0, 0, 0);
        auto lift = [&](int v, int k) -> int {
                for (int i = LOG - 1; i >= 0; i--) {
                        if (k >> i & 1) {
                                v = up[v][i];
                        }
                }
                return v;
        };
        auto lca = [&](int u, int v) -> int {
                if (depth[u] < depth[v]) std::swap(u, v);
                u = lift(u, depth[u] - depth[v]);
                if (u == v) return u;
                for (int i = LOG - 1; i >= 0; i--) {
                        if (up[u][i] != up[v][i]) {
                                u = up[u][i];
                                v = up[v][i];
                        }
                }
                return up[u][0];
        };
        auto query = [&](int u, int k) -> int {
                int ret = std::numeric_limits<int>::max();
                for (int i = LOG - 1; i >= 0; i--) {
                        if (k >> i & 1) {
                                ret = std::min(ret, flow[u][i]);
                                u = up[u][i];
                        }
                }
                return ret;
        };
        int Q; std::cin >> Q;
        while (Q--) {
                int u, v; std::cin >> u >> v; u--, v--;
                int LCA = lca(u, v);
                std::cout << std::min(query(u, depth[u] - depth[LCA]), query(v, depth[v] - depth[LCA])) << '\n';
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
