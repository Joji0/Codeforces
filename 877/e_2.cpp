// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "alg/acted_monoid/sum_xor.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void solve() {
  INT(N);
  Graph<int> G(N);
  FOR(i, 1, N) {
    INT(p);
    p--;
    G.add(p, i);
  }
  G.build();
  Tree<Graph<int>> T(G);
  VEC(int, A, N);
  vc<int> init(N);
  FOR(i, N) init[T.LID[i]] = A[i];
  Lazy_SegTree<ActedMonoid_Sum_Xor<int>> seg(init);
  INT(Q);
  FOR(Q) {
    STR(s);
    INT(X);
    X--;
    if (s == "get") {
      print(seg.prod(T.LID[X], T.RID[X]));
    } else if (s == "pow") {
      seg.apply(T.LID[X], T.RID[X], 1);
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
