// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        std::vector<std::vector<int>> G(N, std::vector<int>(M)), row(N, std::vector<int>(2, 0)), col(M, std::vector<int>(2, 0));
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
                std::cin >> G[i][j];
                row[i][G[i][j]]++;
                col[j][G[i][j]]++;
        }
        int64_t ans = 0;
        for (int i = 0; i < N; i++) {
                ans += (1LL << row[i][0]) - 1;
                ans += (1LL << row[i][1]) - 1;
        }
        for (int i = 0; i < M; i++) {
                ans += (1LL << col[i][0]) - 1;
                ans += (1LL << col[i][1]) - 1;
        }
        ans -= 1LL * N * M;
        std::cout << ans << '\n';

}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
