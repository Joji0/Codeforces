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

struct DSU {
    vector<int64_t> parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (a < b)
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    // The idea to solve this problem is to realize that a connected component
    // formed by a friendship will be reasonable if and only if for every
    // connected component inside such network is a complete graph. The edge
    // count of such graph is always v * (v - 1) / 2 where v is the number of
    // vertex in the graph.
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    vector<pair<int, int>> edges(m);
    map<int, int64_t> edgeCnt;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.join(u, v);
        edges[i] = {u, v};
    }
    for (int i = 0; i < m; i++) {
        int par1 = dsu.find(edges[i].first), par2 = dsu.find(edges[i].second);
        edgeCnt[par1]++, edgeCnt[par2]++;
    }
    for (auto &[parent, cnt] : edgeCnt) {
        int64_t sz = dsu.sz[parent], expect = sz * (sz - 1) / 2;
        if (cnt / 2 != expect) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
