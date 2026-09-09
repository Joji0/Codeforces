// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        const int MAX_A = 10005;
        std::vector<int> freq(MAX_A, 0);
        int N; std::cin >> N;
        for (int i = 0; i < N; i++) {
                int x; std::cin >> x;
                freq[x]++;
        }
        int ans = 0;
        for (int i = 0; i < MAX_A - 1; i++) {
                ans = std::max(ans, freq[i] + freq[i + 1]);
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
