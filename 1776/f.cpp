#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    map<array<int, 2>, int> edges;
    vector<vector<int>> Graph(N);
    vector<int> color(M, -1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        edges[{u, v}] = i;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    function<void(int, int, int)> dfs = [&](int node, int prev, int prevcol) {
        int col = 0;
        for (auto &nxt : Graph[node]) {
            if (nxt == prev)
                continue;
            if (col == prevcol)
                col++;
            int u = nxt, v = node;
            if (u > v)
                swap(u, v);
            if (color[edges[{u, v}]] == -1) {
                color[edges[{u, v}]] = col;
                dfs(nxt, node, col);
                col++;
            }
        }
    };
    dfs(0, -1, -1);
    set<int> ans;
    for (auto &c : color) {
        ans.insert(c);
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < M; i++) {
        cout << color[i] + 1 << " \n"[i == M - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
