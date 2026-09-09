// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

void solve() {
  INT(a, b, N);
  using mint = modint107;
  auto go = [&](int x) -> bool {
    bool ok = true;
    while (x > 0) {
      ok &= (x % 10 == a || x % 10 == b);
      x /= 10;
    }
    return ok;
  };
  mint ANS = 0;
  FOR(i, 0, N + 1) {
    int sum = a * i + (N - i) * b;
    bool ok = go(sum);
    if (ok) ANS += fact<mint>(N) * fact_inv<mint>(i) * fact_inv<mint>(N - i);
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
