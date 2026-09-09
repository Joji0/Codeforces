// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/unionfind/rollback_unionfind.hpp"

void solve() {
        int N, M; std::cin >> N >> M;
        RollbackDSU dsu(N);
        for (int i = 0; i < M; i++) {
                int u, v; std::cin >> u >> v; u--, v--;
                dsu.join(u, v);
        }
        int Q; std::cin >> Q;
        assert(dsu.history.size() == M);
        while (Q--) {
                int K; std::cin >> K;
                int ok = 1;
                for (int i = 0; i < K; i++) {
                        int x, y; std::cin >> x >> y; x--, y--;
                        if (!dsu.join(x, y)) {
                                ok = 0;
                        }
                }
                if (ok) std::cout << "Nop\n";
                else std::cout << "Cycle\n";
                dsu.rollback(M);
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
