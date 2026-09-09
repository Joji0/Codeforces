// 我思う、故に我在り
#include <bits/stdc++.h>
#include "graph/tree/ReRooting.hpp"
#include "monoid/Add.hpp"

void solve() {
        int N; std::cin >> N;
        std::vector<int> W(N);
        for (auto& x : W) {
                std::cin >> x;
                if (!x) --x;
        }
        Graph<int> T(N);
        for (int i = 0; i < N - 1; i++) {
                int a, b; std::cin >> a >> b; a--, b--;
                T.add_edge(a, b);
        }
        auto f = [&](int sum, const Edge<int>& e) -> int {
                return std::max(0, sum + W[e.from]);
        };
        auto reroot = make_rerooting<Add<int>>(T, f);
        for (int i = 0; i < N; i++) {
                int ans = reroot[i] + W[i];
                std::cout << ans << " \n"[i == N - 1];
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        // std::cin >> tc;
        while (tc--) solve();
        return 0;
}
