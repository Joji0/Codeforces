// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        std::vector<int> P(N), ori(N);
        for (int i = 0; i < N; i++) {
                std::cin >> P[i]; P[i]--;
                ori[P[i]] = i;
        }
        for (int i = 0; i < M; i++) {
                int l, r, x; std::cin >> l >> r >> x; l--, r--, x--;
                std::vector<int> temp(N);
                for (int j = l; j <= r; j++) {
                        temp[P[j]]++;
                }
                int place = 0;
                for (int j = 0; j < N; j++) {
                        if (j == P[x]) break;
                        if (temp[j]) place++;
                }
                // std::cerr << i << " " << place << '\n';
                if (place + l == ori[P[x]]) std::cout << "Yes\n";
                else std::cout << "No\n";
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
