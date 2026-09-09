// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        std::vector<int> A(N + 1);
        for (int i = 1; i <= N; i++) std::cin >> A[i];

        struct Edge { int to, cap, flow, rev; };
        std::vector<std::vector<Edge>> G(N + 2);
        for (int i = 0; i < M; i++) {
                int u, v; std::cin >> u >> v;
                if (v & 1) std::swap(u, v);
                int sz_u = G[u].size();
                int sz_v = G[v].size();
                G[u].emplace_back(v, std::numeric_limits<int>::max(), 0, sz_v);
                G[v].emplace_back(u, 0, 0, sz_u);
        }

        for (int i = 1; i <= N; i += 2) {
                int sz_source = G[0].size();
                int sz_i = G[i].size();
                G[0].emplace_back(i, std::numeric_limits<int>::max(), 0, sz_i);
                G[i].emplace_back(0, 0, 0, sz_source);
        }
        for (int i = 2; i <= N; i+= 2) {
                int sz_sink = G[N + 1].size();
                int sz_i = G[i].size();
                G[N + 1].emplace_back(i, 0, 0, sz_i);
                G[i].emplace_back(N + 1, 0, 0, sz_sink);
        }

        // lets solve this with max flow -> where the nodes are seperated
        // as follows: node with odd index and node with even index.
        // consider the flow from the odd index to even index for each prime,
        // the answer is the sum of such max flows. Construct new graph for each prime
        // and run dinic algorithm. Complexity: idk smth like O(sqrt(N) * M * sqrt(MAX_A))?

        std::set<int> primes;
        for (int i = 1; i <= N; i++) {
                int temp = A[i];
                for (int p = 2; p * p <= temp; p++) {
                        if (temp % p == 0) {
                                primes.insert(p);
                                while (temp % p == 0) temp /= p;
                        }
                }
                if (temp > 1) primes.insert(temp);
        }

        std::vector<int> ptr(N + 2, 0);
        std::vector<int> level(N + 2, -1);
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
                if (pushed == 0) return 0;
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

        int ans = 0;
        for (int idx : primes) {
                // correct the graph for this particular prime
                for (int i = 0; i <= N + 1; i++) {
                        for (auto &e : G[i]) {
                                e.flow = 0;
                        }
                }
                for (int i = 1; i <= N; i += 2) {
                        int cnt = 0, curr = A[i];
                        while (curr % idx == 0) {
                                curr /= idx;
                                cnt++;
                        }
                        G[0][i / 2].cap = cnt;
                }
                for (int i = 2; i <= N; i += 2) {
                        int cnt = 0, curr = A[i];
                        while (curr % idx == 0) {
                                curr /= idx;
                                cnt++;
                        }
                        G[i].back().cap = cnt;
                }

                // run dinic
                while(bfs()) {
                        std::fill(ptr.begin(), ptr.end(), 0);
                        while (int flow = dfs(0, std::numeric_limits<int>::max())) {
                                ans += flow;
                        }
                }
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
