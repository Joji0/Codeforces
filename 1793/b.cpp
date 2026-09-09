// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int x, y; std::cin >> x >> y;
        std::vector<int> A;
        A.emplace_back(x);
        int ok = 0;
        while (1) {
                if (A.back() == x - 1 && A.size() == 2 * (x - y)) break;
                if (!ok) {
                        A.emplace_back(A.back() - 1);
                        if (A.back() == y) {
                                ok = 1;
                        }
                } else {
                        A.emplace_back(A.back() + 1);
                }
        }
        std::cout << A.size() << '\n';
        for (auto &x : A) std::cout << x << " ";
        std::cout << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
