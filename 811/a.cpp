// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int64_t a, b, curr = 1; std::cin >> a >> b;
        int win = 0;
        while (1) {
                if (!win) {
                        if (a < curr) break;
                        a -= curr;
                } else {
                        if (b < curr) break;
                        b -= curr;
                }
                curr++;
                win ^= 1;
        }
        std::cout << (win ? "Valera" : "Vladik") << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
