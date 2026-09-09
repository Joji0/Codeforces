// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        std::string a, b; std::cin >> a >> b;
        int N = a.size(), ok = 1;;
        for (int i = 0; i < N; i++) {
                if (b[i] - 'a' > a[i] - 'a') {
                        ok = 0;
                        break;
                }
        }
        if (!ok) {
                std::cout << "-1\n";
        } else {
                std::string ans;
                for (int i = 0; i < N; i++) {
                        if (a[i] != b[i]) {
                                ans += b[i];
                        } else ans += a[i];
                }
                std::cout << ans << '\n';
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
