// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N, M, K);
  Graph<ll> G(N);
  FOR(M) {
    INT(U, V, W);
    U--, V--;
    G.add(U, V, W);
  }
  G.build();
  vv(ll, dp, N, N);
  FOR(i, N) {
    auto [dist, par] = dijkstra<ll>(G, i);
    dp[i] = dist;
  }
  ll ANS = infty<ll>;
  vc<pi> A;
  FOR(K) {
    INT(a, b);
    a--, b--;
    A.eb(a, b);
  }
  for (auto& e : G.edges) {
    ll curr = 0;
    FOR(i, K) {
      auto [a, b] = A[i];
      curr += min(
          {dp[a][b], dp[a][e.frm] + dp[e.to][b], dp[a][e.to] + dp[e.frm][b]});
    }
    chmin(ANS, curr);
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
