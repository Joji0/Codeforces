// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"

void solve() {
  INT(N, M);
  VEC(bool, A, N);
  Graph<> G(N);
  G.read_tree();
  int ans = 0;
  auto dfs = [&](auto& dfs, int u, int p, int carry) -> void {
    bool leaf = 1;
    int nxt = (A[u] ? carry + 1 : 0);
    for (auto e : G[u]) {
      int v = e.to;
      if (v == p) continue;
      leaf = 0;
      if (nxt <= M) dfs(dfs, v, u, nxt);
    }
    if (leaf && nxt <= M) ans++;
  };
  dfs(dfs, 0, -1, 0);
  print(ans);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
