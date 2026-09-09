// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M);
  Graph<ll, true> G(2 * N);
  FOR(M) {
    INT(U, V);
    LL(W);
    U--, V--;
    G.add(U, V, W);
    G.add(V + N, U + N, W);
  }
  FOR(i, N) G.add(i, i + N, 0);
  G.build();
  vc<ll> ANS(N - 1);
  auto [dist, par] = dijkstra<ll>(G, 0);
  FOR(i, N - 1) {
    if (dist[i + 1 + N] == infty<ll>)
      ANS[i] = -1;
    else
      ANS[i] = dist[i + 1 + N];
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
