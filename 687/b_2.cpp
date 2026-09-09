// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; int64_t K; std::cin >> N >> K;
        int64_t lcm = 1;
        for (int i = 0; i < N; i++) {
                int64_t c; std::cin >> c;
                int64_t gcd = std::gcd(c, K);
                lcm = std::lcm(lcm, gcd);
        }
        if (lcm == K) std::cout << "Yes\n";
        else std::cout << "No\n";
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
