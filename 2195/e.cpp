#include "mod/modint.hpp"
#include <bits/stdc++.h>
using namespace std;
using Mint = ModInt<1000000007>;
int n, L[1 << 20], R[1 << 20];
Mint dp[1 << 20], ans[1 << 20];
void dfs1(int v) {
        if (v == 0) return;
        if (L[v] == 0) {
                dp[v] = 1;
                return;
        }
        dfs1(L[v]), dfs1(R[v]);
        dp[v] = dp[L[v]] + dp[R[v]] + 3;
}
void dfs2(int v, Mint curr) {
        if (v == 0) return;
        Mint nxt = curr + dp[v];
        ans[v] = nxt;
        dfs2(L[v], nxt), dfs2(R[v], nxt);
}
void solve() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
                int l, r;
                cin >> l >> r;
                L[i] = l, R[i] = r;
        }
        dfs1(1);
        dfs2(1, 0);
        for (int i = 1; i <= n; i++) {
                cout << ans[i] << " \n"[i == n];
        }
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        cin >> tc;
        while (tc--) solve();
        return 0;
}
