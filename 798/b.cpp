// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<std::string> A(N);
        std::vector<std::set<std::string>> st(N);
        std::vector<std::vector<std::string>> pos(N);
        for (int i = 0; i < N; i++) {
                std::cin >> A[i];
                std::string curr = A[i];
                int M = A[i].size();
                for (int j = 0; j < M; j++) {
                        st[i].insert(curr);
                        pos[i].emplace_back(curr);
                        char f = curr[0];
                        curr = curr.substr(1, M - 1);
                        curr.push_back(f);
                }
        }
        int ok = 1;
        for (int i = 0; i < N - 1; i++) {
                int curr = 0;
                for (auto &s : st[i]) {
                        curr |= st[i + 1].contains(s);
                }
                ok &= curr;
        }
        if (!ok) {
                std::cout << "-1\n";
                return;
        }
        int ans = std::numeric_limits<int>::max();
        int M = A[0].size();
        for (int i = 0; i < M; i++) {
                std::string target = pos[0][i];
                int curr = 0;
                for (int j = 0; j < N; j++) {
                        curr += find(pos[j].begin(), pos[j].end(), target) - pos[j].begin();
                }
                ans = std::min(ans, curr);
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
