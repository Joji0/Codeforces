// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        assert(N % 6 == 0);
        std::cout << int(sqrt(N / 6)) << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
