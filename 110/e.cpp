// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/unionfind/unionfind.hpp"

void solve() {
        int N; std::cin >> N;
        std::vector<int64_t> sub(N, 0);
        auto check = [](int64_t w) -> bool {
                bool ok = true;
                for (char c : std::to_string(w)) {
                        ok &= (c == '4' || c == '7');
                        if (!ok) break;
                }
                return ok;
        };
        UnionFind dsu(N);
        for (int i = 0; i < N - 1; i++) {
                int u, v; int64_t w;
                std::cin >> u >> v >> w; u--, v--;
                if (!check(w)) dsu.join(u, v);
        }
        auto groups = dsu.groups();
        int64_t ans = 0;
        for (auto &v : groups) {
                int64_t sz = v.size();
                ans += sz * (N - sz) * (N - sz - 1);
        }
        std::cout << ans << '\n';

}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
