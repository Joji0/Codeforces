#include "ds/unionfind/rollback_unionfind.hpp"
#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
vector<int> W[1 << 20];
vector<pair<int, int>> q[1 << 20];
struct Edge {
        int from, to, w, id;
};
vector<Edge> Edges;
vector<bool> ans;
void solve() {
        cin >> N >> M;
        Edges.push_back({-1, -1, -1, -1});
        for (int i = 1; i <= M; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                W[w].push_back(i);
                Edges.push_back({u, v, w, i});
        }
        cin >> Q;
        ans.assign(Q + 1, true);
        for (int i = 1; i <= Q; i++) {
                int k;
                cin >> k;
                for (int j = 0; j < k; j++) {
                        int id;
                        cin >> id;
                        q[Edges[id].w].push_back({i, id});
                }
        }
        RollbackDSU dsu(N + 1);
        for (int i = 1; i < 1 << 20; i++) {
                sort(q[i].begin(), q[i].end());
                int idx = 0;
                while (idx < (int)q[i].size()) {
                        int snap = dsu.snapshot();
                        int qid = q[i][idx].first;
                        bool ok = true;
                        while (idx < (int)q[i].size() && q[i][idx].first == qid) {
                                int eid = q[i][idx].second;
                                if (!dsu.join(Edges[eid].from, Edges[eid].to)) ok = false;
                                idx++;
                        }
                        if (!ok) ans[qid] = false;
                        dsu.rollback(snap);
                }
                for (int eid : W[i]) {
                        dsu.join(Edges[eid].from, Edges[eid].to);
                }
        }
        for (int i = 1; i <= Q; i++) {
                if (ans[i])
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        // cin >> tc;
        while (tc--) solve();
        return 0;
}
