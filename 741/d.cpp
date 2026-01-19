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

struct DSUOnTree {
    int n;
    vector<int> head, to, nxt;
    int ec;
    vector<int> parent, sub, heavy, tin, tout, euler;
    int timer;
    DSUOnTree(int n = 0) { init(n); }
    void init(int n) {
        this->n = n;
        head.assign(n, -1);
        to.clear();
        nxt.clear();
        to.reserve(2 * max(1, n - 1));
        nxt.reserve(2 * max(1, n - 1));
        ec = 0;
        parent.assign(n, -1);
        sub.assign(n, 0);
        heavy.assign(n, -1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        euler.clear();
        euler.reserve(n);
        timer = 0;
    }
    void add_edge(int u, int v) {
        to.push_back(v);
        nxt.push_back(head[u]);
        head[u] = ec++;
        to.push_back(u);
        nxt.push_back(head[v]);
        head[v] = ec++;
    }
    void dfs_sz(int node, int par) {
        parent[node] = par;
        sub[node] = 1;
        int best = -1, bestsz = 0;
        for (int e = head[node]; e != -1; e = nxt[e]) {
            int nx = to[e];
            if (nx == par)
                continue;
            dfs_sz(nx, node);
            sub[node] += sub[nx];
            if (sub[nx] > bestsz) {
                bestsz = sub[nx];
                best = nx;
            }
        }
        heavy[node] = best;
    }
    void euler_tour(int node, int par) {
        tin[node] = timer++;
        euler.push_back(node);
        for (int e = head[node]; e != -1; e = nxt[e]) {
            int nx = to[e];
            if (nx == par)
                continue;
            euler_tour(nx, node);
        }
        tout[node] = timer;
    }
    template <class AddNode> void add_subtree(int node, AddNode add_node) {
        for (int i = tin[node]; i < tout[node]; i++)
            add_node(euler[i]);
    }
    template <class RemoveNode>
    void remove_subtree(int node, RemoveNode remove_node) {
        for (int i = tin[node]; i < tout[node]; i++)
            remove_node(euler[i]);
    }
    template <class AddNode, class RemoveNode, class Answer>
    void dfs_solve(int node, int par, bool keep, AddNode add_node,
                   RemoveNode remove_node, Answer answer) {
        for (int e = head[node]; e != -1; e = nxt[e]) {
            int nx = to[e];
            if (nx == par || nx == heavy[node])
                continue;
            dfs_solve(nx, node, false, add_node, remove_node, answer);
        }
        if (heavy[node] != -1)
            dfs_solve(heavy[node], node, true, add_node, remove_node, answer);

        for (int e = head[node]; e != -1; e = nxt[e]) {
            int nx = to[e];
            if (nx == par || nx == heavy[node])
                continue;
            add_subtree(nx, add_node);
        }
        add_node(node);
        answer(node);
        if (!keep)
            remove_subtree(node, remove_node);
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

const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    DSUOnTree dsu(N);
    vector<int> par(N, -1);
    vector<char> ch(N);
    for (int i = 1; i < N; i++) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        par[i] = p;
        ch[i] = c;
        dsu.add_edge(p, i);
    }
    vector<int> out(N, -1);
    vector<int> best(1 << 22, -INF);
    vector<int> depth(N), touched, mask(N, 0);
    depth[0] = mask[0] = 0;
    for (int i = 1; i < N; i++) {
        depth[i] = depth[par[i]] + 1;
        mask[i] = mask[par[i]] ^ (1 << (ch[i] - 'a'));
    }
    auto upd = [&](int m, int val) {
        if (best[m] == -INF)
            touched.push_back(m);
        if (val > best[m]) {
            best[m] = val;
        }
    };
    auto reset = [&]() {
        for (int &m : touched) {
            best[m] = -INF;
        }
        touched.clear();
    };
    auto ans = [&](const int &node) {
        int res = 0;
        for (int e = dsu.head[node]; e != -1; e = dsu.nxt[e]) {
            int nxt = dsu.to[e];
            if (nxt == dsu.parent[node])
                continue;
            chmax(res, out[nxt]);
        }
        reset();
        upd(mask[node], depth[node]);
        for (int e = dsu.head[node]; e != -1; e = dsu.nxt[e]) {
            int nxt = dsu.to[e];
            if (nxt == dsu.parent[node])
                continue;
            for (int i = dsu.tin[nxt]; i < dsu.tout[nxt]; i++) {
                int u = dsu.euler[i];
                int m = mask[u];
                int best_depth = best[m];
                for (int k = 0; k < 22; k++) {
                    chmax(best_depth, best[m ^ (1 << k)]);
                }
                if (best_depth != -INF) {
                    chmax(res, depth[u] + best_depth - 2 * depth[node]);
                }
            }
            for (int i = dsu.tin[nxt]; i < dsu.tout[nxt]; i++) {
                int u = dsu.euler[i];
                upd(mask[u], depth[u]);
            }
        }
        out[node] = res;
        reset();
    };
    dsu.run(0, [](const int &node) {}, [](const int &node) {}, ans);
    for (int i = 0; i < N; i++) {
        assert(out[i] != -1);
        cout << out[i] << " \n"[i == N - 1];
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
