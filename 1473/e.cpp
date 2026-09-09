// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M);
  Graph<ll, true> G(4 * N);
  FOR(M) {
    INT(U, V);
    LL(W);
    U--, V--;
    FOR(step, 2) {
      if (step) swap(U, V);
      FOR(i, 4) G.add(U + i * N, V + i * N, W);
      // 0->1 || 2->3
      G.add(U, V + N, 0);
      G.add(U + 2 * N, V + 3 * N, 0);
      // 0->2 || 1->3
      G.add(U, V + 2 * N, 2 * W);
      G.add(U + N, V + 3 * N, 2 * W);
      // 0->3
      G.add(U, V + 3 * N, W);
    }
  }
  G.build();
  auto [dist, par] = dijkstra<ll>(G, 0);
  FOR(i, 1, N) { print(dist[i + 3 * N]); }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
