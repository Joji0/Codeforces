// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int64_t a, b, n, m; std::cin >> a >> b >> n >> m;
        std::cout << std::min(n * std::min(a, b), (n / (m + 1)) * (a * m) + (n % (m + 1)) * std::min(a, b)) << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
