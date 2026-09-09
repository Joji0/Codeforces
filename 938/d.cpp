// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M);
  Graph<ll> G(N + 1);
  FOR(M) {
    INT(U, V);
    LL(W);
    G.add(U, V, W * 2);
  }
  VEC(ll, A, N);
  FOR(i, 1, N + 1) G.add(0, i, A[i - 1]);
  G.build();
  auto [dist, par] = dijkstra<ll>(G, 0);
  FOR(i, 1, N + 1) {
    assert(dist[i] != infty<ll>);
    print(dist[i]);
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
