// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<int> A(N);
        for (auto& x : A) std::cin >> x;
        for (int i = 0; i < N; i++) {
                int L = 0, R = i, ans = i;
                while (L <= R) {
                        int mid = (L + R) >> 1;
                        int dist = i - mid + 1;
                        if (A[mid] >= dist) {
                                ans = mid;
                                R = mid - 1;
                        } else {
                                L = mid + 1;
                        }
                }
                std::cout << i - ans + 1 << " \n"[i == N - 1];
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        std::cin >> tc;
        while (tc--) solve();
        return 0;
}
