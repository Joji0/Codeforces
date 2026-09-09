// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"

void solve() {
  INT(N);
  set<pi> st;
  Graph<int> G(N);
  vc<int> FROM(N - 1), TO(N - 1);
  FOR(i, N - 1) {
    INT(U, V);
    U--, V--;
    G.add(U, V, 1, i);
    FROM[i] = U, TO[i] = V;
  }
  G.build();
  Tree<Graph<int>> T(G);
  auto f_ee = [&](int d1, int d2) -> int { return d1 + d2; };
  auto f_ev = [&](int d, int v) -> int { return d; };
  auto f_ve = [&](int d, auto e) -> int {
    return d + bool(e.frm != FROM[e.id]);
  };
  int unit = 0;
  Rerooting_dp<decltype(T), int> dp(T, f_ee, f_ev, f_ve, unit);
  int best = infty<int>;
  vc<int> capital;
  FOR(i, N) {
    if (dp[i] < best) {
      best = dp[i];
      capital.clear();
      capital.eb(i + 1);
    } else if (dp[i] == best)
      capital.eb(i + 1);
  }
  print(best);
  print(capital);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
