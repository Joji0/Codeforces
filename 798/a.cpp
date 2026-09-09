// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        std::string s; std::cin >> s;
        int N = s.size();
        auto ok = [&](std::string x) -> bool {
                int X = x.size(), ret = 1;
                for (int i = 0; i <= X / 2; i++) {
                        ret &= x[i] == x[X - i - 1];
                }
                return ret;
        };
        for (int i = 0; i <= N / 2; i++) {
                std::string curr = s;
                if (curr[i] == s[N - i - 1] && i != N - i - 1) continue;
                curr[i] = s[N - i - 1];
                if (ok(curr)) {
                        std::cout << "YES\n";
                        return;
                }
        }
        std::cout << "NO\n";
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
