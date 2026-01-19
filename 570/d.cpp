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
template <class Fun> struct y_combinator_result {
    Fun fun;
    template <class T>
    explicit y_combinator_result(T &&fun) : fun(std::forward<T>(fun)) {}

    template <class... Args> decltype(auto) operator()(Args &&...args) {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int N, M;
vector<int> BIT, depth;
vector<vector<array<int, 2>>> Query;
vector<char> out;

struct DSUOnTree {
    int n;
    vector<vector<int>> G;
    vector<int> parent, sub, heavy, tin, tout, euler;
    int timer;
    DSUOnTree(int n = 0) { init(n); }
    void init(int n) {
        this->n = n;
        G.assign(n, {});
        parent.assign(n, -1);
        sub.assign(n, 0);
        heavy.assign(n, -1);
        tin.assign(n, 0), tout.assign(n, 0);
        euler.clear();
        euler.reserve(n);
        timer = 0;
    }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void dfs_sz(int node, int par) {
        parent[node] = par;
        sub[node] = 1;
        int best = -1, bestsz = 0;
        for (int &nxt : G[node]) {
            if (nxt == par)
                continue;
            depth[nxt] = depth[node] + 1;
            dfs_sz(nxt, node);
            sub[node] += sub[nxt];
            if (sub[nxt] > bestsz) {
                bestsz = sub[nxt];
                best = nxt;
            }
        }
        heavy[node] = best;
    }
    void euler_tour(int node, int par) {
        tin[node] = timer++;
        euler.push_back(node);
        for (int &nxt : G[node]) {
            if (nxt == par)
                continue;
            euler_tour(nxt, node);
        }
        tout[node] = timer;
    }
    template <class AddNode> void add_subtree(int node, AddNode add_node) {
        for (int i = tin[node]; i < tout[node]; i++) {
            add_node(euler[i]);
        }
    }
    template <class RemoveNode>
    void remove_subtree(int node, RemoveNode remove_node) {
        for (int i = tin[node]; i < tout[node]; i++) {
            remove_node(euler[i]);
        }
    }
    template <class AddNode, class RemoveNode, class Answer>
    void dfs_solve(int node, int par, bool keep, AddNode add_node,
                   RemoveNode remove_node, Answer answer) {
        for (int &nxt : G[node]) {
            if (nxt == par || nxt == heavy[node])
                continue;
            dfs_solve(nxt, node, false, add_node, remove_node, answer);
        }
        if (heavy[node] != -1) {
            dfs_solve(heavy[node], node, true, add_node, remove_node, answer);
        }
        for (int &nxt : G[node]) {
            if (nxt == par || nxt == heavy[node])
                continue;
            add_subtree(nxt, add_node);
        }
        add_node(node);
        answer(node);
        if (!keep) {
            remove_subtree(node, remove_node);
        }
    }
    template <class AddNode, class RemoveNode, class Answer>
    void run(int root, AddNode add_node, RemoveNode remove_node,
             Answer answer) {
        euler.clear();
        timer = 0;
        dfs_sz(root, -1);
        euler_tour(root, -1);
        dfs_solve(root, -1, true, add_node, remove_node, answer);
    }
};

void solve() {
    cin >> N >> M;
    BIT.assign(N + 67, 0), depth.assign(N + 67, 0), Query.assign(N + 67, {}),
        out.assign(M + 67, '0');
    DSUOnTree dsu(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        dsu.add_edge(i, p);
    }
    string s;
    cin >> s;
    auto add = [&](const auto &node) {
        BIT[depth[node]] ^= (1 << (s[node] - 'a'));
    };
    auto ans = [&](const auto &node) {
        for (auto &[height, id] : Query[node]) {
            out[id] = (popcnt32(BIT[height]) <= 1 ? '1' : '0');
        }
    };
    for (int i = 0; i < M; i++) {
        int v, h;
        cin >> v >> h;
        v--, h--;
        Query[v].push_back({h, i});
    }
    dsu.run(0, add, add, ans);
    for (int i = 0; i < M; i++) {
        cout << (out[i] == '1' ? "Yes\n" : "No\n");
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
