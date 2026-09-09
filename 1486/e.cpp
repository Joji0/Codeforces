// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  INT(N, M);
  Graph<ll> G(N);
  G.read_graph(M, true);
  vv(ll, dp, N, 51, infty<ll>);
  using P = pair<ll, pi>;
  pq_min<P> que;
  dp[0][0] = 0;
  que.push({0, {0, 0}});
  while (len(que)) {
    auto [dist, p] = POP(que);
    auto [u, prev] = p;
    if (dist > dp[u][prev]) continue;
    for (auto& e : G[u]) {
      int v = e.to;
      ll w = e.cost;
      if (!prev) {
        if (chmin(dp[v][w], dist + 0)) {
          que.push({dp[v][w], {v, w}});
        }
      } else {
        ll cost = (prev + w) * (prev + w);
        if (chmin(dp[v][0], dist + cost)) {
          que.push({dp[v][0], {v, 0}});
        }
      }
    }
  }
  FOR(i, N) print((dp[i][0] == infty<ll> ? -1 : dp[i][0]));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
