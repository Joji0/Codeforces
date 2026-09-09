// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<int> A(N);
        for (auto &x : A) std::cin >> x;
        int L = 0, R = N - 1, mn = 1, mx = N;
        while (L <= R) {
                if (A[L] == mn) {
                        L++;
                        mn++;
                } else if (A[L] == mx) {
                        L++;
                        mx--;
                } else if (A[R] == mn) {
                        R--;
                        mn++;
                } else if (A[R] == mx) {
                        R--;
                        mx--;
                } else {
                        std::cout << L + 1 << " " << R + 1 << '\n';
                        return;
                }
        }
        std::cout << "-1\n";
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
