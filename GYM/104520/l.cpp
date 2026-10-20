#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"

void solve() {
	INT(N);
	Graph<ll> G(N);
	FOR(i, N - 1) {
		INT(par);
		--par;
		G.add(par, i + 1);
	}
	G.build();
	VEC(ll, C, N);
	VEC(ll, A, N);
	VEC(ll, B, N);
	vv(ll, dp, N, 2, infty<ll>);
	if (A[0] != B[0]) {
		dp[0][1] = C[0];
	} else {
		dp[0][0] = 0;
	}
	auto dfs = [&](auto&& self, int v, int p) -> void {
		dp[v][1] = C[v];
		dp[v][0] = 0;
		for (auto& e : G[v]) {
			int u = e.to;
			if (u == p) continue;
			self(self, u, v);
			if (B[u] == A[v]) {
				dp[v][0] += min(dp[u][0], dp[u][1]);
			} else {
				dp[v][0] += dp[u][1];
			}
			if (A[u] == B[v]) {
				dp[v][1] += min(dp[u][0], dp[u][1]);
			} else {
				dp[v][1] += dp[u][1];
			}
		}
		SHOW(v, p, dp[v][0], dp[v][1]);
	};
	dfs(dfs, 0, -1);
	print(min(dp[0][0], dp[0][1]));
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// int t = 1;
	INT(t);
	FOR(t)
	solve();

	return 0;
}
