// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, K; std::cin >> N >> K;
        std::vector<int> A(N), ok(N, 1);
        for (auto &x : A) std::cin >> x;
        sort(A.begin(), A.end());
        int ans = 0;
        int L = 0, R = N - 1;
        while (L <= R) {
                if (L == R) {
                        if (A[L] >= K) ans++;
                        break;
                }
                if (A[R] >= K) {
                        ans++;
                        R--;
                } else if (A[L] + A[R] >= K) {
                        ans++;
                        L++;
                        R--;
                } else L++;
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
