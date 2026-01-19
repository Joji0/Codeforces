#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int N, M, H;
    cin >> N >> M >> H;
    vector<vector<array<int, 2>>> Graph(N);
    set<int> horse;
    for (int i = 0; i < H; i++) {
        int u;
        cin >> u;
        u--;
        horse.insert(u);
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        Graph[u].push_back({v, w});
        Graph[v].push_back({u, w});
    }
    auto dijkstra = [&](int src, vector<vector<int64_t>> &dist) {
        priority_queue<array<int64_t, 3>, vector<array<int64_t, 3>>, greater<>>
            pq;
        pq.push({0, src, (horse.contains(src))});
        dist[src][(horse.contains(src))] = 0;
        while (!pq.empty()) {
            auto [d, node, ok] = pq.top();
            pq.pop();
            if (dist[node][ok] != d)
                continue;
            for (auto &[nxt, w] : Graph[node]) {
                int nw = (ok ? w / 2 : w);
                int nok = ok | (horse.contains(nxt));
                if (dist[nxt][nok] > d + nw) {
                    dist[nxt][nok] = d + nw;
                    pq.push({dist[nxt][nok], nxt, nok});
                }
            }
        }
    };
    vector<vector<int64_t>> d1(N, vector<int64_t>(2, INF)),
        d2(N, vector<int64_t>(2, INF));
    dijkstra(0, d1), dijkstra(N - 1, d2);
    int64_t ans = INF;
    for (int i = 0; i < N; i++) {
        int64_t nd1 = min(d1[i][0], d1[i][1]), nd2 = min(d2[i][0], d2[i][1]);
        if (nd1 == INF || nd2 == INF)
            continue;
        ans = min(ans, max(nd1, nd2));
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
