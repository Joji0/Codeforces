#include <bits/stdc++.h>
using namespace std;

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v)
        out << x << ' ';
    return out;
}
template <typename T> istream &operator>>(istream &in, vector<vector<T>> &vv) {
    for (auto &v : vv)
        in >> v;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &vv) {
    for (const auto &v : vv)
        out << v << '\n';
    return out;
}
template <typename T> void print(const vector<T> &v) {
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << '\n';
}
template <typename T> void _print(const T &x) { cerr << x; }
template <typename T> void _print(const vector<T> &v) {
    cerr << '[';
    bool first = true;
    for (const auto &x : v) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(x);
    }
    cerr << ']';
}
template <typename T> void _print(const vector<vector<T>> &vv) {
    cerr << "DEBUG:\n[\n";
    for (const auto &v : vv) {
        cerr << "  ";
        _print(v);
        cerr << '\n';
    }
    cerr << "]\n";
}
template <typename T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'

int bfs(int node, vector<vector<int>> const &adj) {
    int n = adj.size(), ret = 0;
    vector<bool> vis(n, false);
    vector<int> dis(n, 0);
    queue<int> q;
    q.push(node);
    dis[node] = 0;
    vis[node] = true;
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        for (auto &x : adj[f]) {
            if (vis[x])
                continue;
            q.push(x);
            dis[x] = dis[f] + 1;
            vis[x] = true;
            chmax(ret, dis[x]);
        }
    }
    return ret;
}

void solve() {
    // The greedy part of this problem is to always try to connect the longest
    // chain of a tree to another longest chain
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        vector<vector<int>> adj(ni, vector<int>());
        for (int j = 0; j < ni - 1; j++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int chain = 0;
        for (int j = 0; j < ni; j++) {
            chmax(chain, bfs(j, adj));
        }
        ans += chain;
    }
    cout << ans << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
