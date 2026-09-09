// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "graph/shortest_path/dijkstra.hpp"
#include "ds/unionfind/unionfind.hpp"

void solve() {
  INT(N, M);
  Graph<ll> G(N), BASE(N);
  G.read_graph(M, true);
  UnionFind dsu(N);
  vc<Edge<ll>> E = G.edges;
  vc<int> discarded;
  sort(E.begin(), E.end(),
       [](const auto& a, const auto& b) { return a.cost < b.cost; });
  for (auto& e : E) {
    if (dsu.merge(e.frm, e.to)) {
      BASE.add(e.frm, e.to, e.cost);
    } else {
      discarded.eb(e.frm);
      discarded.eb(e.to);
    }
  }
  UNIQUE(discarded);
  int K = len(discarded);
  vv(ll, dp, K, N);
  FOR(i, K) {
    auto [dist, par] = dijkstra<ll>(G, discarded[i]);
    dp[i] = dist;
  }
  BASE.build();
  Tree<Graph<ll>> T(BASE);
  INT(Q);
  FOR(Q) {
    INT(U, V);
    U--, V--;
    ll ANS = T.dist_weighted(U, V);
    FOR(i, K) { chmin(ANS, dp[i][U] + dp[i][V]); }
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
