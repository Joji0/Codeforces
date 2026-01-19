#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Tree(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    function<void(vector<int> &, int, int, int)> dfs =
        [&](vector<int> &d, int node, int par, int dist) {
            for (auto &nxt : Tree[node]) {
                if (nxt == par)
                    continue;
                d[nxt] = dist + 1;
                dfs(d, nxt, node, dist + 1);
            }
        };
    vector<int> d1(N, 0), d2(N, 0);
    dfs(d1, 0, -1, 0);
    int id = -1, mx = *max_element(d1.begin(), d1.end());
    for (int i = 0; i < N; i++) {
        if (d1[i] == mx) {
            id = i;
            break;
        }
    }
    assert(id != -1);
    dfs(d2, id, -1, 0);
    cout << *max_element(d2.begin(), d2.end()) << '\n';
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
