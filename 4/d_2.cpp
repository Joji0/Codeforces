// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"

template <typename T, bool tie_is_left = true>
struct Monoid_Max_Idx {
  using value_type = pair<T, int>;
  using X = value_type;
  static X op(X x, X y) {
    if (x.fi > y.fi) return x;
    if (x.fi < y.fi) return y;
    if (x.se > y.se) swap(x, y);
    return (tie_is_left ? x : y);
  }
  static constexpr X unit() { return {0, -1}; }
  static constexpr bool commute = true;
};

#include "ds/segtree/segtree.hpp"

struct Env {
  int w, h, id;
  bool operator<(const Env& other) const {
    if (w != other.w) return w < other.w;
    return h > other.h;
  }
};

void solve() {
  INT(N, W, H);
  vc<Env> A;
  FOR(i, N) {
    INT(w, h);
    if (w > W && h > H) A.eb(w, h, i);
  }
  if (A.empty()) {
    print(0);
    return;
  }
  sort(all(A));
  SegTree<Monoid_Max_Idx<int>> seg(1000005);
  vc<int> par(N, -1);
  FOR(i, len(A)) {
    auto [w, h, id] = A[i];
    auto [best, max_idx] = seg.prod(0, h);
    par[id] = max_idx;
    auto [prev, prev_idx] = seg.get(h);
    if (best + 1 > prev) {
      seg.set(h, {best + 1, id});
    }
  }
  int sz = seg.prod_all().fi;
  print(sz);
  vc<int> path;
  int curr = seg.prod_all().se;
  // SHOW(seg.prod_all());
  while (curr != -1) {
    path.eb(curr + 1);
    curr = par[curr];
  }
  assert(len(path) == sz);
  reverse(all(path));
  print(path);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
