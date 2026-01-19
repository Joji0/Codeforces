#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> Tree(N), up(N, vector<int>(LOG, -1)), tinDepth(N);
    vector<int> depth(N), tin(N, 0), tout(N, 0);
    set<int> roots;
    for (int i = 0; i < N; i++) {
        int par;
        cin >> par;
        if (!par) {
            roots.insert(i);
        } else {
            par--;
            Tree[par].push_back(i);
        }
    }
    vector<bool> vis(N, false);
    int timer = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        vis[node] = true;
        tin[node] = timer++;
        for (auto &nxt : Tree[node]) {
            if (nxt == par)
                continue;
            depth[nxt] = depth[node] + 1;
            up[nxt][0] = node;
            for (int j = 1; j < LOG; j++) {
                if (up[nxt][j - 1] != -1) {
                    up[nxt][j] = up[up[nxt][j - 1]][j - 1];
                } else {
                    up[nxt][j] = -1;
                }
            }
            dfs(nxt, node);
        }
        tout[node] = timer;
    };
    for (int i = 0; i < N; i++) {
        if (!vis[i] && roots.contains(i))
            dfs(i, -1);
    }
    for (int i = 0; i < N; i++) {
        tinDepth[depth[i]].push_back(tin[i]);
    }
    for (int i = 0; i < N; i++) {
        sort(tinDepth[i].begin(), tinDepth[i].end());
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int v, p;
        cin >> v >> p;
        v--;
        int curr = v;
        for (int j = LOG - 1; j >= 0; j--) {
            if (p & (1LL << j)) {
                curr = up[curr][j];
                if (curr == -1)
                    break;
            }
        }
        if (curr == -1) {
            cout << "0 ";
            continue;
        }
        int L = tin[curr], R = tout[curr], dv = depth[v];
        int ans = upper_bound(tinDepth[dv].begin(), tinDepth[dv].end(), R) -
                  lower_bound(tinDepth[dv].begin(), tinDepth[dv].end(), L);
        cout << ans - 1 << " ";
    }
    cout << '\n';
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
