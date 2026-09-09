// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void solve() {
  INT(N);
  Graph<int> G(N);
  G.read_tree();
  Tree<Graph<int>> T(G);
  Lazy_SegTree<ActedMonoid_Sum_Add<int>> seg(N);
  INT(K);
  FOR(K) {
    INT(a, b);
    a--, b--;
    auto path = T.get_path_decomposition(a, b, true);
    for (auto& [l, r] : path) {
      if (l > r) swap(l, r);
      seg.apply(l, r + 1, 1);
    }
  }
  vc<int> ANS;
  FOR(i, N - 1) { ANS.eb(seg.get(T.LID[T.e_to_v(i)])); }
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
