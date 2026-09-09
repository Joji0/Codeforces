// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; int64_t P; std::cin >> N >> P;
        std::vector<std::pair<int64_t, int64_t>> DAT(N);
        int64_t sum = 0;
        for (int i = 0; i < N; i++) {
                std::cin >> DAT[i].first >> DAT[i].second;
                sum += DAT[i].first;
        }
        if (sum <= P) {
                std::cout << "-1\n";
                return;
        }
        long double l = 0, r = 1e15, ans = -1;
        for (int iter = 0; iter < 300; iter++) {
                long double mid = (l + r) / 2.0, tot = 0;
                for (int i = 0; i < N; i++) {
                        tot += std::max((long double)0.0, DAT[i].first * mid - DAT[i].second);
                }
                if (tot <= P * mid) {
                        l = mid;
                        ans = mid;
                } else {
                        r = mid;
                }
        }
        assert(ans != -1);
        std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
