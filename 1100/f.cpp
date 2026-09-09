// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/bit.hpp"
#include "ds/segtree/segtree.hpp"

struct Fast_Basis {
  int dat[20] = {0};
  void add(int v) {
    while (v) {
      int k = topbit(v);
      if (!dat[k]) {
        dat[k] = v;
        return;
      }
      v ^= dat[k];
    }
  }
  int get_max() {
    int res = 0;
    FOR_R(i, 20) { chmax(res, res ^ dat[i]); }
    return res;
  }
};

struct Monoid_FastBasis {
  using value_type = Fast_Basis;
  using X = value_type;
  static X op(X x, const X& y) {
    FOR(i, 20) {
      if (y.dat[i]) x.add(y.dat[i]);
    }
    return x;
  }
  static X unit() { return Fast_Basis(); }
  static constexpr bool commute = true;
};

void solve() {
  INT(N);
  VEC(int, A, N);
  SegTree<Monoid_FastBasis> seg(N, [&](int i) {
    Fast_Basis ret;
    ret.add(A[i]);
    return ret;
  });
  INT(Q);
  FOR(Q) {
    INT(l, r);
    l--, r--;
    Fast_Basis res;
    int L = l + seg.size;
    int R = r + 1 + seg.size;
    while (L < R) {
      if (L & 1) {
        FOR(i, 20) if (seg.dat[L].dat[i]) res.add(seg.dat[L].dat[i]);
        L++;
      }
      if (R & 1) {
        R--;
        FOR(i, 20) if (seg.dat[R].dat[i]) res.add(seg.dat[R].dat[i]);
      }
      L >>= 1;
      R >>= 1;
    }
    print(res.get_max());
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
