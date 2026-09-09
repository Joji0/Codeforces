// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        std::vector<std::pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
                std::cin >> A[i].first;
                A[i].second = i;
        }
        sort(A.begin(), A.end());
        std::vector<bool> vis(N, 0);
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < N; i++) {
                if (!vis[i]) {
                        std::vector<int> curr;
                        int now = i;
                        while (1) {
                                if (vis[now]) break;
                                vis[now] = 1;
                                curr.emplace_back(now + 1);
                                now = A[now].second;
                        }
                        ans.emplace_back(curr);
                }
        }
        std::cout << ans.size() << '\n';
        for (auto &v : ans) {
                std::cout << v.size() << " ";
                for (auto &x : v) std::cout << x << " ";
                std::cout << '\n';
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
