// 我思う、故に我在り
#include <bits/stdc++.h>
#include "math/convolution/Convolution.hpp"

void solve() {
        int N, K; std::cin >> N >> K;
        using mint = modint998;
        std::vector<int> A(N);
        int max = 0;
        for (auto &x : A) {
                std::cin >> x;
                max = std::max(max, x);
        }
        std::vector<mint> polynomial(max + 1);
        for (auto &x : A) {
                polynomial[x]++;
        }
        std::vector<mint> res = Convolution::poly_pow_bool(polynomial, K, K * max + 1);
        for (int i = 0; i < (int)res.size(); i++) {
                if (res[i].get() > 0) {
                        std::cout << i << " ";
                }
        }
        std::cout << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        // std::cin >> tc;
        while (tc--) solve();
        return 0;
}
