// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

void solve() {
  INT(N);
  VEC(int, A, N);
  const vc<int> PRIME = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                         31, 37, 41, 43, 47, 53, 59, 61, 67};
  vc<int> Basis(19, 0);
  FOR(i, N) {
    int mask = 0;
    FOR_R(bit, 19) {
      int cnt = 0;
      while (A[i] % PRIME[bit] == 0) {
        A[i] /= PRIME[bit];
        cnt++;
      }
      if (cnt & 1) mask |= 1 << bit;
    }
    A[i] = mask;
    FOR_R(bit, 19) {
      if (A[i] >> bit & 1) {
        if (!Basis[bit]) {
          Basis[bit] = A[i];
          break;
        }
        chmin(A[i], A[i] ^ Basis[bit]);
      }
    }
  }
  using mint = modint107;
  int cnt = 0;
  FOR(i, 19) if (Basis[i]) cnt++;
  print(mint(mint(2).pow(N - cnt) - 1));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
