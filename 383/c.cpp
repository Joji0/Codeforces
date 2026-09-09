// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void solve() {
  INT(N, M);
  VEC(ll, A, N);
  Graph<ll> G(N);
  G.read_tree();
  Tree<Graph<ll>> T(G);
  vc<ll> init_odd(N, 0), init_even(N, 0);
  FOR(i, N) {
    if (T.depth[i] & 1)
      init_odd[T.LID[i]] = A[i];
    else
      init_even[T.LID[i]] = A[i];
  }
  Lazy_SegTree<ActedMonoid_Sum_Add<ll>> seg_odd(init_odd), seg_even(init_even);
  FOR(M) {
    INT(type);
    if (type == 1) {
      INT(X);
      LL(val);
      X--;
      if (T.depth[X] & 1) {
        seg_odd.apply(T.LID[X], T.RID[X], val);
        seg_even.apply(T.LID[X], T.RID[X], -val);
      } else {
        seg_odd.apply(T.LID[X], T.RID[X], -val);
        seg_even.apply(T.LID[X], T.RID[X], val);
      }
    } else {
      INT(X);
      X--;
      if (T.depth[X] & 1)
        print(seg_odd.get(T.LID[X]));
      else
        print(seg_even.get(T.LID[X]));
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
