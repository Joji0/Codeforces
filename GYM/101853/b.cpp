// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N; std::cin >> N;
        const int MAX_A = 1000005;
        std::vector<int> A(N + 1), last(MAX_A, -1);
        std::vector<char> P(N + 1);
        for (int i = 1; i <= N; i++) std::cin >> A[i];
        for (int i = 1; i <= N; i++) std::cin >> P[i];
        struct Edge { int to, cap, flow, rev; };

        std::vector<std::vector<Edge>> G(N + 2);
        for (int i = 1; i <= N; i++) {
                int curr = A[i];
                for (int j = 2; j * j <= curr; j++) {
                        int cnt = 0;
                        while (curr % j == 0) {
                                curr /= j;
                                cnt++;
                        }
                        if (cnt > 0) {
                                if (last[j] != -1 && P[last[j]] != P[i]) {
                                        int u = last[j], v = i;
                                        if (P[u] == 'F') std::swap(u, v);
                                        G[u].emplace_back(v, 1, 0, G[v].size());
                                        G[v].emplace_back(u, 0, 0, G[u].size() - 1);
                                } else {
                                        last[j] = i;
                                }
                        }
                }
                if (curr > 1) {
                        if (last[curr] != -1 && P[last[curr]] != P[i]) {
                                int u = last[curr], v = i;
                                if (P[u] == 'F') std::swap(u, v);
                                G[u].emplace_back(v, 1, 0, G[v].size());
                                G[v].emplace_back(u, 0, 0, G[u].size() - 1);
                        } else {
                                last[curr] = i;
                        }
                }
        }

        for (int i = 1; i <= N; i++) {
                if (P[i] == 'M') {
                        G[0].emplace_back(i, 1, 0, G[i].size());
                        G[i].emplace_back(0, 0, 0, G[0].size() - 1);
                } else {
                        G[i].emplace_back(N + 1, 1, 0, G[N + 1].size());
                        G[N + 1].emplace_back(i, 0, 0, G[i].size() - 1);
                }
        }

        std::vector<int> level(N + 2, -1), ptr(N + 2, 0);
        auto bfs = [&]() -> bool {
                std::fill(level.begin(), level.end(), -1);
                std::queue<int> q;
                level[0] = 0;
                q.push(0);
                while (!q.empty()) {
                        int v = q.front(); q.pop();
                        for (auto &[u, cap, flow, rev] : G[v]) {
                                if (level[u] == -1 && cap - flow > 0) {
                                        level[u] = level[v] + 1;
                                        q.push(u);
                                }
                        }
                }
                return level[N + 1] != -1;
        };

        auto dfs = [&](this auto &dfs, int v, int pushed) -> int {
                if (!pushed) return 0;
                if (v == N + 1) return pushed;
                for (int &i = ptr[v]; i < G[v].size(); i++) {
                        auto &[u, cap, flow, rev] = G[v][i];
                        if (level[u] != level[v] + 1 || cap - flow == 0) continue;
                        int push = dfs(u, std::min(pushed, cap - flow));
                        if (push == 0) continue;
                        flow += push;
                        G[u][rev].flow -= push;
                        return push;
                }
                return 0;
        };

        int matched = 0;
        while(bfs()) {
                std::fill(ptr.begin(), ptr.end(), 0);
                while (int curr = dfs(0, std::numeric_limits<int>::max())) {
                        matched += curr;
                }
        }

        std::cout << N - matched << '\n';
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        std::cin >> tc;
	while (tc--) solve();
	return 0;
}
