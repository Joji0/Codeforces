/*
 * Note that this solution is still very dirty. There are lots of optimization
 * that can be done (still got AC tho).
 * */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[100005];
vector<int> ans;
bool vis[100005];
int parent[100005];
int final = -1, init = -1;
int n, m, k;
set<int> st;

bool dfs(int node, int par, int depth) {
    parent[node] = par;
    vis[node] = true;
    for (auto &u : adj[node]) {
        if (u == par || (st.find(u) != st.end() && depth < k))
            continue;
        st.insert(u);
        if (u == init && vis[u] && depth >= k) {
            // cout << "depth: " << depth << "\n";
            final = node;
            ans.push_back(final);
            return true;
        } else if (vis[u])
            continue;
        if (dfs(u, node, depth + 1)) {
            ans.push_back(node);
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        if ((int)adj[i].size() > maxx) {
            init = i;
        }
    }
    st.insert(init);
    dfs(init, -1, 0);
    // vector<int> ans;
    // while (final != 1) {
    //     ans.push_back(final);
    //     final = parent[final];
    // }
    // ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &u : ans) {
        cout << u << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
