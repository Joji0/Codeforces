// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        std::vector<int> C(N);
        for (auto &x : C) std::cin >> x;
        std::vector<std::vector<int>> T(N);
        for (int i = 0; i < N - 1; i++) {
                int u, v; std::cin >> u >> v;
                u--, v--;
                T[u].emplace_back(v);
                T[v].emplace_back(u);
        }
        std::vector<std::vector<std::pair<int, int>>> Q(N);
        for (int i = 0; i < M; i++) {
                int v, k;
                std::cin >> v >> k; v--;
                Q[v].emplace_back(k, i);
        }
        std::vector<int> sub(N, 0);
        auto calc_size = [&](this auto &go, int v, int p) -> void {
                sub[v] = 1;
                for (int u : T[v]) {
                        if (u == p) continue;
                        go(u, v);
                        sub[v] += sub[u];
                }
        };
        calc_size(0, -1);
        const int MAX_COLOR = 100005;
        std::vector<int> freq(MAX_COLOR, 0), geq(MAX_COLOR, 0), ans(M, -1);
        std::vector<std::vector<int>> vec(N);
        auto dfs = [&](this auto &dfs, int v, int p, int keep) -> void {
                int big = -1, max = 0;
                for (int u : T[v]) {
                        if (u == p) continue;
                        if (sub[u] > max) {
                                big = u;
                                max = sub[u];
                        }
                }
                for (int u : T[v]) {
                        if (u != p && u != big) {
                                dfs(u, v, 0);
                        }
                }
                if (big != -1) {
                        dfs(big, v, 1);
                        swap(vec[v], vec[big]);
                }
                vec[v].push_back(v);
                freq[C[v]]++;
                geq[freq[C[v]]]++;
                for (int u : T[v]) {
                        if (u != p && u != big) {
                                for (int x : vec[u]) {
                                        vec[v].push_back(x);
                                        freq[C[x]]++;
                                        geq[freq[C[x]]]++;
                                }
                        }
                }
                for (auto [k, id] : Q[v]) {
                        ans[id] = geq[k];
                }
                if (!keep) { // not a big child so reduce this guy
                        for (int u : vec[v]) {
                                geq[freq[C[u]]]--;
                                freq[C[u]]--;
                        }
                }
        };
        dfs(0, -1, 1);
        for (int i = 0; i < M; i++) {
                assert(ans[i] != -1);
                std::cout << ans[i] << '\n';
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
