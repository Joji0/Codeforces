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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> G(N);
        for (int i = 0; i < M; i++) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                G[u].push_back(v), G[v].push_back(u);
        }
        int timer = 0;
        vector<int> vis(N, 0), tin(N, 0), low(N, 0);
        set<array<int, 2>> bridges;
        auto dfs1 = y_combinator([&](auto self, int node, int par) -> void {
                vis[node] = 1;
                low[node] = tin[node] = timer;
                timer++;
                for (auto &nxt : G[node]) {
                        if (nxt == par) continue;
                        if (!vis[nxt]) {
                                self(nxt, node);
                                low[node] = min(low[node], low[nxt]);
                                if (low[nxt] > tin[node]) {
                                        bridges.insert({min(node, nxt), max(node, nxt)});
                                }
                        } else {
                                low[node] = min(low[node], tin[nxt]);
                        }
                }
        });
        dfs1(0, -1);
        int id = 0;
        vector<int> ids(N, -1);
        vis.assign(N, 0);
        auto dfs2 = y_combinator([&](auto self, int node) -> void {
                vis[node] = 1;
                ids[node] = id;
                for (auto &nxt : G[node]) {
                        if (bridges.contains({min(node, nxt), max(node, nxt)})) {
                                continue;
                        } else if (!vis[nxt]) {
                                self(nxt);
                        }
                }
        });
        for (int i = 0; i < N; i++) {
                if (!vis[i]) {
                        dfs2(i);
                        id++;
                }
        }
        int N_bridge = id;
        vector<set<int>> condensed(N_bridge);
        vis.assign(N, 0);
        auto dfs3 = y_combinator([&](auto self, int node) -> void {
                vis[node] = 1;
                for (auto &nxt : G[node]) {
                        if (!vis[nxt]) {
                                if (ids[nxt] != ids[node]) {
                                        condensed[ids[node]].insert(ids[nxt]);
                                        condensed[ids[nxt]].insert(ids[node]);
                                }
                                self(nxt);
                        }
                }
        });
        dfs3(0);
        vector<int> dist(N_bridge, 0), vis2(N_bridge, 0);
        auto diam = y_combinator([&](auto self, int node) -> void {
                vis2[node] = 1;
                for (auto &nxt : condensed[node]) {
                        if (!vis2[nxt]) {
                                dist[nxt] = dist[node] + 1;
                                self(nxt);
                        }
                }
        });
        diam(0);
        int mx = max_element(dist.begin(), dist.end()) - dist.begin();
        dist.assign(N_bridge, 0), vis2.assign(N_bridge, 0);
        diam(mx);
        cout << *max_element(dist.begin(), dist.end()) << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
