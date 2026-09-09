// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"

struct Data {
  ll cost, sz;
};

void solve() {
  INT(N);
  VEC(ll, A, N);
  Graph<ll> G(N);
  G.read_tree();
  Tree<Graph<ll>> T(G);
  auto f_ee = [&](Data d1, Data d2) -> Data {
    return {d1.cost + d2.cost, d1.sz + d2.sz};
  };
  auto f_ev = [&](Data d, int v) -> Data { return {d.cost, d.sz + A[v]}; };
  auto f_ve = [&](Data d, auto e) -> Data { return {d.cost + d.sz, d.sz}; };
  Data unit = {0, 0};
  Rerooting_dp<decltype(T), Data> dp(T, f_ee, f_ev, f_ve, unit);
  ll ANS = 0;
  FOR(i, N) chmax(ANS, dp[i].cost);
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
