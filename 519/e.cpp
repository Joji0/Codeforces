#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> Tree(N), up(N, vector<int>(LOG, -1));
    vector<int> depth(N), sub(N, 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    up[0][0] = 0;
    for (int j = 1; j < LOG; j++) {
        up[0][j] = up[up[0][j - 1]][j - 1];
    }
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            depth[nxt] = depth[node] + 1;
            up[nxt][0] = node;
            for (int j = 1; j < LOG; j++) {
                up[nxt][j] =
                    (up[nxt][j - 1] == -1 ? -1 : up[up[nxt][j - 1]][j - 1]);
            }
            dfs(nxt, node);
            sub[node] += sub[nxt];
        }
    };
    dfs(0, -1);
    auto LCA = [&](int a, int b) -> int {
        if (depth[a] < depth[b])
            swap(a, b);
        int k = depth[a] - depth[b];
        for (int j = LOG - 1; j >= 0; j--) {
            if (k & (1LL << j)) {
                a = up[a][j];
            }
        }
        if (a == b)
            return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != -1 && up[b][j] != -1 && up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    };
    auto dist = [&](int a, int b) -> int {
        int lca = LCA(a, b);
        return depth[a] + depth[b] - 2 * depth[lca];
    };
    auto lift = [&](int u, int d) -> int {
        for (int j = LOG - 1; j >= 0; j--) {
            if (d & (1LL << j)) {
                u = up[u][j];
                if (u == -1)
                    return -1;
            }
        }
        return u;
    };
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int d = dist(x, y);
        if (d & 1) {
            cout << "0\n";
            continue;
        }
        if (depth[x] == depth[y]) {
            int mid = LCA(x, y);
            if (x == y) {
                cout << N << '\n';
                continue;
            }
            int sub1 = lift(x, depth[x] - depth[mid] - 1);
            int sub2 = lift(y, depth[y] - depth[mid] - 1);
            cout << N - sub[sub1] - sub[sub2] << '\n';

        } else {
            if (depth[x] < depth[y])
                swap(x, y);
            int k = d / 2;
            int sub1 = lift(x, k);
            int sub2 = lift(x, k - 1);
            cout << sub[sub1] - sub[sub2] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
