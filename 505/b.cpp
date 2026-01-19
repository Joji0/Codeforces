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
    for (auto &x : v)
        cout << x << " ";
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
template <typename A, typename B> void _print(const pair<A, B> &p) {
    cerr << "(";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << ")";
}
template <typename T, size_t N> void _print(const array<T, N> &a) {
    cerr << "[";
    for (size_t i = 0; i < N; i++) {
        _print(a[i]);
        if (i + 1 < N)
            cerr << ", ";
    }
    cerr << "]";
}
template <typename T, size_t N> void _print(const T (&a)[N]) {
    cerr << "[";
    for (size_t i = 0; i < N; i++) {
        _print(a[i]);
        if (i + 1 < N)
            cerr << ", ";
    }
    cerr << "]";
}
template <typename T> void _print(const set<T> &s) {
    cerr << "{";
    bool first = true;
    for (auto &x : s) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(x);
    }
    cerr << "}";
}
template <typename T> void _print(const multiset<T> &s) {
    cerr << "{";
    bool first = true;
    for (auto &x : s) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(x);
    }
    cerr << "}";
}
template <typename K, typename V> void _print(const map<K, V> &m) {
    cerr << "{";
    bool first = true;
    for (auto &p : m) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(p);
    }
    cerr << "}";
}
template <typename K, typename V> void _print(const unordered_map<K, V> &m) {
    cerr << "{";
    bool first = true;
    for (auto &p : m) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(p);
    }
    cerr << "}";
}
template <typename T> void _print(const deque<T> &dq) {
    cerr << "dq(";
    for (int i = 0; i < dq.size(); i++) {
        _print(dq[i]);
        if (i + 1 < dq.size())
            cerr << ", ";
    }
    cerr << ")";
}
template <typename T> void _print(queue<T> q) {
    cerr << "q(";
    bool first = true;
    while (!q.empty()) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(q.front());
        q.pop();
    }
    cerr << ")";
}
template <typename T> void _print(stack<T> st) {
    cerr << "st(";
    bool first = true;
    vector<T> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(temp[i]);
    }
    cerr << ")";
}
template <typename T> void _print(priority_queue<T> pq) {
    cerr << "pq(";
    bool first = true;
    while (!pq.empty()) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(pq.top());
        pq.pop();
    }
    cerr << ")";
}
template <typename T> void _print(priority_queue<T, vector<T>, greater<T>> pq) {
    cerr << "minpq(";
    bool first = true;
    while (!pq.empty()) {
        if (!first)
            cerr << ", ";
        first = false;
        _print(pq.top());
        pq.pop();
    }
    cerr << ")";
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
template <typename T> void offset(T o, vector<T> &x) {
    for (auto &a : x)
        a += o;
}
#define CLR_RESET "\033[0m"
#define CLR_BOLD "\033[1m"
#define CLR_CYAN "\033[36m"
#define CLR_YELLOW "\033[33m"
#define CLR_DIM "\033[2m"
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void debug_impl(const char *name, T &&value) {
    cerr << CLR_BOLD << CLR_CYAN << name << CLR_RESET << " = " << CLR_YELLOW;
    _print(value);
    cerr << CLR_RESET << '\n';
}
template <typename T, typename... Args>
void debug_impl(const char *names, T &&value, Args &&...args) {
    const char *comma = strchr(names, ',');
    cerr << CLR_BOLD << CLR_CYAN;
    cerr.write(names, comma - names);
    cerr << CLR_RESET << " = " << CLR_YELLOW;
    _print(value);
    cerr << CLR_RESET << " " << CLR_DIM << "| " << CLR_RESET;
    debug_impl(comma + 1, args...);
}
inline int popcnt64(int64_t x) { return __builtin_popcountll(x); }
inline int safe_ctz64(int64_t x) { return x ? __builtin_ctzll(x) : 64; }
inline int safe_clz64(int64_t x) { return x ? __builtin_clzll(x) : 64; }
inline int64_t lsone64(int64_t x) { return x & -x; }
inline int64_t msbone64(int64_t x) { return 1LL << (63 - __builtin_clzll(x)); }
inline bool ispow2_64(int64_t x) { return x && !(x & (x - 1)); }
inline int popcnt32(int x) { return __builtin_popcount(x); }
inline int safe_ctz32(int x) { return x ? __builtin_ctz(x) : 32; }
inline int safe_clz32(int x) { return x ? __builtin_clz(x) : 32; }
inline int lsone32(int x) { return x & -x; }
inline int msbone32(int x) { return 1 << (31 - __builtin_clz(x)); }
inline bool ispow2_32(int x) { return x && !(x & (x - 1)); }

struct DSU {
    vector<int> parent, sz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
        return false;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    map<int, vector<array<int, 2>>> mp;
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        mp[c].push_back({u, v});
    }
    map<int, DSU> dsu;
    for (auto &[color, V] : mp) {
        dsu.emplace(color, DSU(N));
        for (auto &[u, v] : V) {
            dsu[color].join(u, v);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int ans = 0;
        for (auto &[color, d] : dsu) {
            if (d.same(u, v)) {
                ans++;
            }
        }
        cout << ans << '\n';
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
