// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<int> A(N);
        int64_t g = 0;
        for (int i = 0; i < N; i++) {
                std::cin >> A[i];
                g = std::gcd(g, A[i]);
        }
        if (g > 1) {
                std::cout << "YES\n0\n";
                return;
        }
        int ans = 0;
        for (int i = 0; i < N;) {
                if (A[i] & 1) {
                        if (i + 1 < N && A[i + 1] & 1) {
                                ans += 1;
                                i += 2;
                        } else {
                                ans += 2;
                                i++;
                        }
                } else i++;
        }
        std::cout << "YES\n" << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
