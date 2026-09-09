// 我思う、故に我在り
#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(x);
  vc<string> ops;
  vc<ll> Basis(60, 0), board = {x};
  ll v = x;
  FOR(i, 30) {
    string s = to_string(v) + " + " + to_string(v);
    ops.eb(s);
    v <<= 1;
    board.eb(v);
  }
  FOR(i, len(board)) {
    ll nw = board[i];
    FOR_R(bit, 60) {
      if (nw >> bit & 1) {
        if (!Basis[bit]) {
          Basis[bit] = nw;
          break;
        }
        string s = to_string(nw) + " ^ " + to_string(Basis[bit]);
        ops.eb(s);
        chmin(nw, nw ^ Basis[bit]);
      }
    }
  }
  SHOW(board);
  FOR_R(i, 60) { SHOW(i, Basis[i]); }
  // ll nw = board.back() + 1;
  // FOR_R(bit, 60) {
  //   if (nw >> bit & 1) {
  //     if (!Basis[bit]) SHOW(bit);
  //     assert(Basis[bit]);
  //     string s = to_string(nw) + " ^ " + to_string(Basis[bit]);
  //     ops.eb(s);
  //     chmin(nw, nw ^ Basis[bit]);
  //   }
  // }
  // string s = to_string(board.back()) + " ^ " + to_string(board.back() + 1);
  // ops.eb(s);
  print(len(ops));
  for (string& s : ops) print(s);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t = 1;
  // cin >> t;
  FOR(t) solve();

  return 0;
}
