// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        std::string s; std::cin >> s;
        auto calc = [&](std::string x) -> int {
                int ret = 0;
                for (int i = 0; i < x.size() - 1; i++) {
                        ret += bool(x[i] == 'V' && x[i + 1] == 'K');
                }
                return ret;
        };
        int ans = calc(s);
        for (int i = 0; i < s.size(); i++) {
                std::string curr = s;
                curr[i] = curr[i] == 'V' ? 'K' : 'V';
                ans = std::max(ans, calc(curr));
        }
        std::cout << ans << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
