// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<std::vector<int>> T(N);
        for (int i = 0; i < N - 1; i++) {
                int u, v; std::cin >> u >> v; u--, v--;
                T[u].emplace_back(v);
                T[v].emplace_back(u);
        }
        auto go = [&](this auto& go, int v, int p, std::vector<int>& d) -> void {
                for (int u : T[v]) {
                        if (u == p) continue;
                        d[u] = d[v] + 1;
                        go(u, v, d);
                }
        };
        std::vector<int> d(N);
        go(0, -1, d);
        auto at = std::max_element(d.begin(), d.end()) - d.begin();
        d.assign(N, 0);
        go(at, -1, d);
        int r = *std::max_element(d.begin(), d.end());
        int64_t ans = 3LL * int64_t(r);
        std::cout << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
