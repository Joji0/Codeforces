#include <bits/stdc++.h>
using namespace std;

template <class Fun> struct y_combinator_result {
        Fun fun;
        template <class T> explicit y_combinator_result(T &&fun) : fun(std::forward<T>(fun)) {}

        template <class... Args> decltype(auto) operator()(Args &&...args) {
                return fun(std::ref(*this), std::forward<Args>(args)...);
        }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve() {
        constexpr int INF = 1 << 30;
        int N, M;
        cin >> N >> M;
        vector<vector<array<int, 2>>> G(N);
        for (int i = 0; i < M; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                u--, v--;
                G[u].push_back({v, w});
                G[v].push_back({u, w});
        }
        int x, y;
        cin >> x >> y;
        x--, y--;
        int timer = 0;
        vector<int> tin(N, 0), low(N, 0), vis(N, 0);
        vector<array<int, 3>> bridges;
        auto dfs = y_combinator([&](auto self, int node, int par) -> void {
                vis[node] = 1;
                tin[node] = low[node] = timer;
                timer++;
                for (auto &[nxt, w] : G[node]) {
                        if (nxt == par) continue;
                        if (!vis[nxt]) {
                                self(nxt, node);
                                low[node] = min(low[node], low[nxt]);
                                if (low[nxt] > tin[node]) {
                                        bridges.push_back({node, nxt, w});
                                }
                        } else {
                                low[node] = min(low[node], tin[nxt]);
                        }
                }
        });
        dfs(0, -1);
        auto dijkstra = [&](int src, vector<int> &dist) {
                priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
                dist[src] = 0;
                pq.push({0, src});
                while (!pq.empty()) {
                        auto [d, node] = pq.top();
                        pq.pop();
                        if (d != dist[node]) continue;
                        for (auto &[nxt, w] : G[node]) {
                                if (dist[nxt] > d + w) {
                                        dist[nxt] = d + w;
                                        pq.push({dist[nxt], nxt});
                                }
                        }
                }
        };
        vector<int> dx(N, INF), dy(N, INF);
        dijkstra(x, dx), dijkstra(y, dy);
        int ans = INF;
        for (auto &[u, v, w] : bridges) {
                ans = min({ans, max(dx[u], dy[v]), max(dx[v], dy[u])});
        }
        cout << ans << '\n';
}

int main() {
        freopen("robots.in", "r", stdin);
        freopen("robots.out", "w", stdout);

        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
