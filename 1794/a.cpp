// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<std::string> A;
        for (int i = 0; i < 2 * N - 2; i++) {
                std::string s; std::cin >> s;
                if (s.size() == N - 1) A.emplace_back(s);
        }
        assert(A.size() == 2);
        reverse(A[0].begin(), A[0].end());
        if (A[0] == A[1]) {
                std::cout << "YES\n";
        } else {
                std::cout << "NO\n";
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        int tc = 1;
        std::cin >> tc;
        while (tc--) solve();
        return 0;
}
