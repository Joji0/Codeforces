// 我思う、故に我在り
#include <bits/stdc++.h>
#include "monoid/add.hpp"
#include "ds/segtree/segtree.hpp"

void solve() {
        int N; std::cin >> N;
        std::vector<int64_t> A(N), B(N), map(N, -1);
        for (auto &x : A) {
                std::cin >> x;
                x--;
        }
        for (auto &x : B) {
                std::cin >> x;
                x--;
        }
        for (int i = 0; i < N; i++) {
                map[B[i]] = i;
        }
        SegTree<AddMonoid<int64_t>> seg(N);
        int64_t ans = 0;
        for (int i = 0; i < N; i++) {
                ans += seg.query(map[A[i]], N - 1);
                seg.update(map[A[i]], 1);
        }
        std::cout << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
