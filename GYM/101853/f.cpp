// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        int m = M * 60, tot = 0;
        for (int i = 0; i < N; i++) {
                std::string s, e; std::cin >> s >> e;
                int hs = stoi(s.substr(0, 2)), ms = stoi(s.substr(3, 2)), he = stoi(e.substr(0, 2)), me = stoi(e.substr(3, 2));
                if (ms != 0) {
                        tot += 60 - ms;
                        hs++;
                        ms = 0;
                }
                tot += (he - hs) * 60 + me - ms;
        }
        std::cout << (tot >= m ? "YES" : "NO") << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
