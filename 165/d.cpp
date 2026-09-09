// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "alg/monoid/add.hpp"
#include "ds/segtree/segtree.hpp"

void solve() {
  INT(N);
  Graph<ll> G(N);
  G.read_tree();
  Tree<Graph<ll>> T(G);
  vc<ll> BASE(N, 1);
  SegTree<Monoid_Add<ll>> seg(BASE);
  INT(Q);
  FOR(Q) {
    INT(type);
    if (type == 1) {
      INT(V);
      V--;
      seg.set(T.LID[T.e_to_v(V)], 1);
    } else if (type == 2) {
      INT(V);
      V--;
      seg.set(T.LID[T.e_to_v(V)], infty<int>);
    } else {
      INT(a, b);
      a--, b--;
      ll ANS = 0;
      int ok = 1;
      auto path = T.get_path_decomposition(a, b, true);
      for (auto& [l, r] : path) {
        if (l > r) swap(l, r);
        ANS += seg.prod(l, r + 1);
        if (ANS >= infty<int>) {
          ok = 0;
          break;
        }
      }
      if (!ok)
        print(-1);
      else
        print(ANS);
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
