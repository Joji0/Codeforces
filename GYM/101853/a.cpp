// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, Q; std::cin >> N >> Q;
        std::vector<int> A(N);
        std::map<int, int> map;
        for (auto &x : A) {
                std::cin >> x;
                map[x]++;
        }
        while (Q--) {
                int t; std::cin >> t;
                if (t == 1) {
                        int p, v; std::cin >> p >> v; p--;
                        if (--map[A[p]] == 0) map.erase(A[p]);
                        A[p] = v;
                        map[A[p]]++;
                } else {
                        std::cout << map.size() - map.contains(0) << '\n';
                }
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
