// 我思う、故に我在り
#include <bits/stdc++.h>

void solve() {
        int N, M; std::cin >> N >> M;
        std::vector<std::vector<char>> G(N, std::vector<char>(M));
        int fx = -1, fy = -1;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
                std::cin >> G[i][j];
                if (G[i][j] == 'F') fx = i, fy = j;
        }
        const std::vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        auto go = [&]() -> std::vector<char> {
                std::queue<std::pair<int, int>> q;
                std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
                std::vector<std::vector<std::pair<int, int>>> parent(N, std::vector<std::pair<int, int>>(M, {-1, -1}));
                q.emplace(0, 0);
                vis[0][0] = 1;
                while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (int i = 0; i < 4; i++) {
                                int nx = x + dx[i], ny = y + dy[i];
                                if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && G[nx][ny] != '*') {
                                        vis[nx][ny] = 1;
                                        parent[nx][ny] = {x, y};
                                        q.emplace(nx, ny);
                                }
                        }
                }
                assert(vis[fx][fy] == 1);
                std::vector<char> path;
                int x = fx, y = fy;
                while (x > 0 || y > 0) {
                        auto &[px, py] = parent[x][y];
                        assert(px != -1 && py != -1);
                        if (px == x - 1) path.emplace_back('D');
                        else if (px == x + 1) path.emplace_back('U');
                        else if (py == y - 1) path.emplace_back('R');
                        else if (py == y + 1) path.emplace_back('L');
                        else assert(false);
                        x = px, y = py;
                }
                reverse(path.begin(), path.end());
                return path;
        };
        std::vector<char> ans = go();
        // std::cerr << "HERE" << std::endl;
        // for (char c : ans) std::cerr << c << " ";
        // std::cerr << std::endl;
        // std::cerr << "HERE" << std::endl;
        bool swap_UD = 0, swap_LR = 0, checked_LR = 0, checked_UD = 0;
        int x = 0, y = 0, i = 0, op = 0;
        while (1) {
                if (i == ans.size() || (x == fx && y == fy)) break;
                if (!checked_LR && ans[i] == 'R') {
                        std::cout << "L" << std::endl;
                        ++op;
                        int gx, gy;
                        std::cin >> gx >> gy;
                        gx--, gy--;
                        if (gx == fx && gy == fy) break;
                        if (gx == x && gy == y + 1) {
                                swap_LR = 1;
                                // correct the position
                                std::cout << "R" << std::endl;
                                std::cin >> gx >> gy; gx--, gy--;
                                if (gx == fx && gy == fy) break;
                                ++op;
                        } else {
                                // i++;
                        }
                        checked_LR = 1;
                        x = gx, y = gy;
                } else if (!checked_UD && ans[i] == 'D') {
                        std::cout << "U" << std::endl;
                        ++op;
                        int gx, gy;
                        std::cin >> gx >> gy;
                        gx--, gy--;
                        if (gx == fx && gy == fy) break;
                        if (gx == x + 1 && gy == y) {
                                swap_UD = 1;
                                std::cout << "D" << std::endl;
                                std::cin >> gx >> gy;
                                gx--, gy--;
                                if (gx == fx && gy == fy) break;
                                ++op;
                        } else {
                                // i++;
                        }
                        checked_UD = 1;
                        x = gx, y = gy;
                } else {
                        if (ans[i] == 'R') {
                                if (swap_LR) std::cout << "L" << std::endl;
                                else std::cout << "R" << std::endl;
                        } else if (ans[i] == 'D') {
                                if (swap_UD) std::cout << "U" << std::endl;
                                else std::cout << "D" << std::endl;
                        } else if (ans[i] == 'L') {
                                if (swap_LR) std::cout << "R" << std::endl;
                                else std::cout << "L" << std::endl;
                        } else {
                                if (swap_UD) std::cout << "D" << std::endl;
                                else std::cout << "U" << std::endl;
                        }
                        i++;
                        int gx, gy; std::cin >> gx >> gy; gx--, gy--;
                        if (gx == fx && gy == fy) break;
                        x = gx, y = gy;
                        ++op;
                }
        }
        assert(op <= 2 * N * M);
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
