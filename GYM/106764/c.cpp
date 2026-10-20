#include "my_template.hpp"
#include "other/io.hpp"

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve() {
	INT(R, C);
	vv(char, G, R, C);
	FOR(i, R) {
		FOR(j, C) {
			char c;
			read(c);
			G[i][j] = c;
		}
	}
	// SHOW(G);
	INT(Q);
	FOR(Q) {
		STR(s);
		auto dfs = [&](auto&& self, int x, int y, int d, vc<vc<bool>>& vis) -> bool {
			if (d == len(s) - 1) return true;
			vis[x][y] = 1;
			FOR(i, 4) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vis[nx][ny] && G[nx][ny] == s[d + 1]) {
					if (self(self, nx, ny, d + 1, vis)) return true;
				}
			}
			vis[x][y] = 0;
			return false;
		};
		FOR(i, R) {
			FOR(j, C) {
				if (s[0] == G[i][j]) {
					vv(bool, vis, R, C, 0);
					if (dfs(dfs, i, j, 0, vis)) {
						print("YES");
						goto DONE;
					}
				}
			}
		}
		print("NO");
	DONE:
	}
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t = 1;
	// INT(t);
	FOR(t)
	solve();

	return 0;
}
