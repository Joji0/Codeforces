// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"

struct Node {
  int val, level;
};

struct Monoid_Xenia {
  using X = Node;
  using value_type = Node;
  static constexpr X op(const X& x, const X& y) noexcept {
    X res;
    res.level = x.level + 1;
    if (x.level % 2 == 0) {
      res.val = x.val | y.val;
    } else {
      res.val = x.val ^ y.val;
    }
    return res;
  }
  static constexpr X unit() { return {0, 0}; }
  static constexpr bool commute = true;
};

#include "ds/segtree/segtree.hpp"

void solve() {
  INT(N, M);
  vc<Node> A;
  FOR(1 << N) {
    INT(v);
    A.eb(v, 0);
  }
  SegTree<Monoid_Xenia> seg(A);
  FOR(M) {
    INT(p, b);
    p--;
    seg.set(p, {b, 0});
    print(seg.prod_all().val);
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
