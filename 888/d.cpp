// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"

ll fact[1005], C[1005][1005];

ll D(int n) {
  if (n == 0) return 1;
  if (n == 1) return 0;
  return (n - 1) * (D(n - 1) + D(n - 2));
}

void solve() {
  fact[0] = 1;
  FOR(i, 1, 1005) fact[i] = fact[i - 1] * i;
  FOR(i, 1005) C[i][0] = 1;
  C[1][1] = 1;
  FOR(i, 2, 1005) {
    C[i][1] = 1;
    FOR(j, 2, i) { C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; }
    C[i][i] = 1;
  }
  INT(N, K);
  ll ANS = 0;
  FOR(i, K + 1) ANS += C[N + 1][i + 1] * D(i);
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
