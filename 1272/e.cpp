// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N);
  VEC(int, A, N);
  Graph<ll, true> G(N);
  vc<int> odd, even;
  FOR(i, N) {
    if (A[i] & 1)
      odd.eb(i);
    else
      even.eb(i);
    if (i - A[i] >= 0) G.add(i - A[i], i);
    if (i + A[i] < N) G.add(i + A[i], i);
  }
  G.build();
  auto [dist_odd, par_odd, root_odd] = dijkstra<ll>(G, odd);
  auto [dist_even, par_even, root_even] = dijkstra<ll>(G, even);
  vc<ll> ANS(N);
  FOR(i, N) {
    if (A[i] & 1)
      ANS[i] = dist_even[i];
    else
      ANS[i] = dist_odd[i];
    if (ANS[i] == infty<ll>) ANS[i] = -1;
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
