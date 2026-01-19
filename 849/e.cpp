#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int64_t w;
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<array<int64_t, 2>>> Graph(N);
    vector<Edge> Edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        u--, v--;
        Graph[u].push_back({v, w});
        Edges.push_back({u, v, w});
    }
    int s;
    cin >> s;
    s--;
    struct SCC {
        int N, comps = 0;
        vector<vector<array<int64_t, 2>>> Graph;
        vector<int> scc;
        SCC() : N(0) {}
        SCC(const vector<vector<array<int64_t, 2>>> &G) { init(G); }
        void init(const vector<vector<array<int64_t, 2>>> &G) {
            N = (int)G.size();
            Graph = G;
            scc.assign(N, -1);
        }
        void TarjanSCC() {
            int id = 0;
            vector<int> ids(N, -1), low(N, 0);
            vector<bool> onStack(N, false);
            stack<int> st;
            function<void(int)> dfs = [&](int node) {
                ids[node] = low[node] = id++;
                onStack[node] = true;
                st.push(node);
                for (auto &[nxt, _] : Graph[node]) {
                    if (ids[nxt] == -1) {
                        dfs(nxt);
                        low[node] = min(low[node], low[nxt]);
                    } else if (onStack[nxt]) {
                        low[node] = min(low[node], ids[nxt]);
                    }
                }
                if (ids[node] == low[node]) {
                    while (true) {
                        assert(!st.empty());
                        int top = st.top();
                        st.pop();
                        onStack[top] = false;
                        low[top] = ids[node];
                        scc[top] = comps;
                        if (top == node)
                            break;
                    }
                    comps++;
                }
            };
            for (int i = 0; i < N; i++) {
                if (ids[i] == -1)
                    dfs(i);
            }
        }
    };
    SCC scc(Graph);
    scc.TarjanSCC();
    auto f = [&](const int64_t wei) -> int64_t {
        int64_t l = 0, r = wei, best = -1;
        while (l <= r) {
            int64_t mid = (l + r) / 2;
            if (wei - (mid * (mid - 1) / 2) >= 0) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        assert(best != -1);
        return best * wei - (best * (best + 1) * (best - 1) / 6);
    };
    int K = scc.comps;
    vector<int64_t> gain(K);
    vector<vector<array<int64_t, 2>>> DAG(K);
    for (auto &[u, v, w] : Edges) {
        if (scc.scc[u] == scc.scc[v]) {
            gain[scc.scc[u]] += f(w);
        } else {
            DAG[scc.scc[u]].push_back({scc.scc[v], w});
        }
    }
    vector<int64_t> memo(K, -1);
    function<int64_t(int)> dp = [&](int node) -> int64_t {
        if (memo[node] != -1)
            return memo[node];
        int64_t best = 0;
        for (auto &[nxt, w] : DAG[node]) {
            best = max(best, dp(nxt) + w);
        }
        return memo[node] = best + gain[node];
    };
    cout << dp(scc.scc[s]) << '\n';
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
