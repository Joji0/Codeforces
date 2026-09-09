// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/sum_assign.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "graph/tree.hpp"

void solve() {
  INT(N);
  Graph<int> G(N);
  G.read_tree();
  Tree<Graph<int>> T(G);
  Lazy_SegTree<ActedMonoid_Sum_Assign<int, -1>> seg(N);
  INT(Q);
  FOR(Q) {
    INT(c, V);
    V--;
    if (c == 1) {
      seg.apply(T.LID[V], T.RID[V], 1);
    } else if (c == 2) {
      auto path = T.get_path_decomposition(V, 0, 0);
      for (auto [l, r] : path) {
        if (l > r) swap(l, r);
        seg.apply(l, r + 1, 0);
      }
    } else {
      print(seg.get(T.LID[V]));
    }
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
