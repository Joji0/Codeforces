// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

void solve() {
  INT(N, Q);
  VEC(int, A, N);
  vvc<pair<int, int>> Query(N);
  FOR(i, Q) {
    INT(L, X);
    L--;
    Query[L].eb(X, i);
  }
  using mint = modint107;
  vc<int> Basis(20, 0), pos(20, -1);
  vc<mint> ANS(Q);
  FOR(i, N) {
    // adding current element
    FOR_R(bit, 20) {
      if (A[i] >> bit & 1) {
        if (!Basis[bit]) {
          Basis[bit] = A[i];
          break;
        } else {
          chmin(A[i], A[i] ^ Basis[bit]);
        }
      }
    }
    int cnt = 0;
    FOR(bit, 20) cnt += bool(Basis[bit]);
    // check whether x can be formed
    for (auto& [X, id] : Query[i]) {
      FOR_R(bit, 20) {
        if (X >> bit & 1) chmin(X, X ^ Basis[bit]);
      }
      if (!X)
        ANS[id] = mint(2).pow(i + 1 - cnt);
      else
        ANS[id] = mint(0);
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
