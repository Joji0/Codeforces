#include <bits/stdc++.h>
using namespace std;

template <class Fun> struct y_combinator_result {
        Fun fun;
        template <class T> explicit y_combinator_result(T &&fun) : fun(std::forward<T>(fun)) {}

        template <class... Args> decltype(auto) operator()(Args &&...args) {
                return fun(std::ref(*this), std::forward<Args>(args)...);
        }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve() {
        const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        int N, M;
        cin >> N >> M;
        vector<vector<char>> G(N, vector<char>(M));
        int px = -1, py = -1;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        cin >> G[i][j];
                        if (G[i][j] == 'S') px = i, py = j;
                }
        }
        vector<vector<vector<int>>> vis(N, vector<vector<int>>(M, vector<int>(2, 67)));
        bool ok = false;
        // prev: 0 -> right, 1 -> down, 2 -> left, 3 -> up
        auto dfs = y_combinator([&](auto self, array<int, 2> pos, int turn, int prev) -> void {
                auto [x, y] = pos;
                if (turn > 2) return;
                if (G[x][y] == 'T') {
                        ok = true;
                        return;
                }
                if (ok) return;
                if (prev != -1) {
                        int axis = prev % 2;
                        if (turn >= vis[x][y][axis]) return;
                        vis[x][y][axis] = turn;
                }
                for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        array<int, 2> npos = {nx, ny};
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && G[nx][ny] != '*') {
                                if (prev == i || prev == -1) {
                                        self(npos, turn, i);
                                } else {
                                        self(npos, turn + 1, i);
                                }
                        }
                }
        });
        array<int, 2> pos = {px, py};
        dfs(pos, 0, -1);
        cout << (ok ? "YES\n" : "NO\n");
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
