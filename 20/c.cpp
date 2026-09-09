// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"
#include "graph/shortest_path/restore_path.hpp"

void solve() {
  INT(N, M);
  Graph<ll> G(N);
  G.read_graph(M, true);
  auto [dist, par] = dijkstra<ll>(G, 0);
  auto path = restore_path(par, N - 1);
  FOR(i, len(path)) path[i]++;
  if (len(path) == 1) {
    print(-1);
    return;
  }
  print(path);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
