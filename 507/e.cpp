// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M);
  Graph<ll> G(N);
  const ll SHIFT = 1'000'000;
  vc<array<int, 3>> edges;
  FOR(M) {
    INT(U, V, Z);
    U--, V--;
    G.add(U, V, SHIFT + (Z ^ 1));
    edges.push_back({min(U, V), max(U, V), Z});
  }
  G.build();
  auto [dist, par] = dijkstra<ll>(G, 0);
  set<pair<int, int>> path_edge;
  int curr = N - 1;
  while (par[curr] != -1) {
    path_edge.insert(mp(min(curr, par[curr]), max(curr, par[curr])));
    curr = par[curr];
  }
  vc<array<int, 3>> VANS;
  FOR(i, M) {
    if (path_edge.contains(mp(edges[i][0], edges[i][1])) && (edges[i][2] ^ 1)) {
      VANS.push_back({edges[i][0] + 1, edges[i][1] + 1, 1});
    } else if (!path_edge.contains(mp(edges[i][0], edges[i][1])) &&
               !(edges[i][2] ^ 1)) {
      VANS.push_back({edges[i][0] + 1, edges[i][1] + 1, 0});
    }
  }
  print(len(VANS));
  print(VANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
