// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        std::string s; int k; std::cin >> s >> k;
        if (s.size() < k) {
                std::cout << "impossible\n";
                return;
        }
        std::map<char, int> map;
        for (char c : s) map[c]++;
        std::cout << std::max(0, k - (int)map.size()) << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
