#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int N, M;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    cin >> M;
    vector<vector<int>> Graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Graph[u].push_back(v);
    }
    auto TarjanSCC = [&]() -> vector<int> {
        int id = 0;
        vector<int> ids(N), low(N);
        vector<bool> vis(N, false), onStack(N, false);
        stack<int> st;
        function<void(int)> dfs = [&](const int &node) {
            ids[node] = low[node] = id++;
            onStack[node] = vis[node] = true;
            st.push(node);
            for (auto &nxt : Graph[node]) {
                if (!vis[nxt]) {
                    dfs(nxt);
                    low[node] = min(low[node], low[nxt]);
                } else if (onStack[nxt]) {
                    low[node] = min(low[node], ids[nxt]);
                }
            }
            if (ids[node] == low[node]) {
                while (!st.empty()) {
                    int top = st.top();
                    st.pop();
                    onStack[top] = false;
                    low[top] = ids[node];
                    if (top == node)
                        break;
                }
            }
        };
        for (int i = 0; i < N; i++) {
            if (!vis[i])
                dfs(i);
        }
        return low;
    };
    vector<int> scc = TarjanSCC();
    map<int, vector<int>> comps;
    for (int i = 0; i < N; i++) {
        comps[scc[i]].push_back(i);
    }
    int64_t ans1 = 0, ans2 = 1;
    for (auto &[compsID, nodes] : comps) {
        int64_t mn = INF;
        for (auto &node : nodes) {
            mn = min(mn, A[node]);
        }
        int64_t cnt = 0;
        for (auto &node : nodes) {
            if (A[node] == mn) {
                cnt++;
            }
        }
        ans2 = (ans2 % MOD) * (cnt % MOD) % MOD;
        ans2 %= MOD;
        ans1 += mn;
    }
    cout << ans1 << " " << ans2 << '\n';
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
