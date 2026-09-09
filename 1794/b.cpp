// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<int> A(N);
        int op = 0;
        for (auto& x: A) {
                std::cin >> x;
                if (x == 1) {
                        x++;
                        op++;
                }
        }
        for (int i = 0; i < N - 1; i++) {
                while (A[i + 1] % A[i] == 0) {
                        // std::cerr << A[i + 1] << " " << A[i] << '\n';
                        A[i + 1]++;
                        op++;
                }
        }
        assert(op <= 2 * N);
        for (auto& x : A) std::cout << x << " ";
        std::cout << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        std::cin >> tc;
        while (tc--) solve();
        return 0;
}
