// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M, K);
  Graph<ll> G(N);
  FOR(M) {
    LL(U, V, X);
    U--, V--;
    G.add(U, V, X);
  }
  vc<pi> T(K);
  FOR(i, K) {
    LL(S, Y);
    S--;
    T[i] = {S, Y};
    G.add(0, S, Y);
  }
  G.build();
  auto [dist, par] = dijkstra<ll>(G, 0);
  int ANS = 0;
  vc<int> ways(N, 0);
  for (auto& e : G.edges) {
    if (dist[e.to] == dist[e.frm] + e.cost) ways[e.to]++;
    if (dist[e.frm] == dist[e.to] + e.cost) ways[e.frm]++;
  }
  FOR(i, K) {
    auto [S, Y] = T[i];
    if (dist[S] < Y)
      ANS++;
    else if (dist[S] == Y && ways[S] > 1) {
      ANS++;
      ways[S]--;
    }
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
