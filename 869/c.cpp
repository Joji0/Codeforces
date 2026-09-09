// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

void solve() {
  using mint = modint998;
  VEC(int, A, 3);
  sort(all(A));
  mint ANS = 1;
  FOR(i, 2) {
    FOR(j, i + 1, 3) {
      int x = A[i], y = A[j];
      if (x < y) swap(x, y);
      mint curr = 0;
      FOR(k, y + 1) { curr += fact<mint>(k) * C<mint>(x, k) * C<mint>(y, k); }
      ANS *= curr;
    }
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
