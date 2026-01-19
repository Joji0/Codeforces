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

struct CentroidDecomposition {
    int n;
    vector<vector<int>> G;
    vector<int> sub, blocked;
    int rootC = -1;
    CentroidDecomposition() {}
    CentroidDecomposition(int n) { init(n); }
    void init(int n) {
        this->n = n;
        G.assign(n, {});
        sub.assign(n, 0);
        blocked.assign(n, 0);
        rootC = -1;
    }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int dfs_sz(int node, int par) {
        sub[node] = 1;
        for (int nxt : G[node]) {
            if (nxt == par || blocked[nxt])
                continue;
            sub[node] += dfs_sz(nxt, node);
        }
        return sub[node];
    }
    int dfs_centroid(int node, int par, int tot) {
        for (int nxt : G[node]) {
            if (nxt == par || blocked[nxt])
                continue;
            if (sub[nxt] > tot / 2)
                return dfs_centroid(nxt, node, tot);
        }
        return node;
    }
    template <class Visitor, class NextAux>
    void collect_subtree(int node, int par, int dist, int child_id, int aux,
                         Visitor &&visitor, NextAux &&next_aux) {
        visitor(node, dist, child_id, aux);
        for (int nxt : G[node]) {
            if (nxt == par || blocked[nxt])
                continue;
            int aux2 = next_aux(node, nxt, aux);
            collect_subtree(nxt, node, dist + 1, child_id, aux2, visitor,
                            next_aux);
        }
    }
    void build_parent_rooted(int node, int par, vector<int> &nodes,
                             vector<int> &parentTmp) {
        parentTmp[node] = par;
        nodes.push_back(node);
        for (int nxt : G[node]) {
            if (nxt == par || blocked[nxt])
                continue;
            build_parent_rooted(nxt, node, nodes, parentTmp);
        }
    }
    template <class OnNode>
    void apply_path_to_centroid(const vector<int> &nodes,
                                const vector<int> &parentTmp,
                                vector<int64_t> &weight, OnNode &&on_node) {
        for (int i = (int)nodes.size() - 1; i >= 0; i--) {
            int v = nodes[i];
            int p = parentTmp[v];
            if (p != -1)
                weight[p] += weight[v];
        }
        for (int v : nodes)
            on_node(v, weight[v]);
        for (int v : nodes)
            weight[v] = 0;
    }
    template <class OnCentroid>
    int decompose(int root, OnCentroid &&on_centroid) {
        fill(blocked.begin(), blocked.end(), 0);
        rootC = decompose_rec(root, -1, on_centroid);
        return rootC;
    }
    template <class OnCentroid>
    int decompose_rec(int entry, int parentCentroid, OnCentroid &on_centroid) {
        int tot = dfs_sz(entry, -1);
        int c = dfs_centroid(entry, -1, tot);
        blocked[c] = 1;
        on_centroid(c, parentCentroid);
        for (int nxt : G[c]) {
            if (blocked[nxt])
                continue;
            decompose_rec(nxt, c, on_centroid);
        }
        return c;
    }
};

struct Visitor {
    vector<array<int, 2>> *out = nullptr;
    Visitor() {}
    Visitor(vector<array<int, 2>> &OUT) { out = &OUT; }
    void operator()(int node, int dist, int child_id, int aux) const {
        (void)dist, (void)child_id;
        out->push_back({node, aux});
    }
};

struct NextAux {
    const string *s = nullptr;
    NextAux() {}
    NextAux(const string &S) { s = &S; }
    int operator()(int from, int to, int aux) const {
        (void)from;
        return aux ^ (1 << ((*s)[to] - 'a'));
    }
};

const int LOG = 20;

void solve() {
    int N;
    cin >> N;
    CentroidDecomposition cd(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cd.add_edge(u, v);
    }
    string s;
    cin >> s;
    vector<array<int, 2>> temp;
    Visitor vis(temp);
    NextAux transition(s);
    vector<int64_t> ans(N, 0), weight(N, 0);
    vector<int> parentTmp(N, -1), nodes, touched;
    nodes.reserve(N), touched.reserve(N);
    static int freq[1 << LOG];
    memset(freq, 0, sizeof(freq));
    auto add = [&](int mask) {
        if (freq[mask] == 0) {
            touched.push_back(mask);
        }
        freq[mask]++;
    };
    auto clear_freq = [&]() {
        for (int m : touched) {
            freq[m] = 0;
        }
        touched.clear();
    };
    auto count = [&](int mask, int c) -> int64_t {
        int base = mask ^ (1 << (s[c] - 'a'));
        int64_t ret = 0;
        ret += freq[base];
        for (int i = 0; i < LOG; i++) {
            int want = (1 << i) ^ base;
            ret += freq[want];
        }
        return ret;
    };
    auto on_centroid = [&](int c, int parC) {
        (void)parC;
        int bitc = (1 << (s[c] - 'a'));
        add(bitc);
        int64_t pair = 0;
        for (int nxt : cd.G[c]) {
            if (cd.blocked[nxt])
                continue;
            temp.clear();
            int aux0 = bitc ^ (1 << (s[nxt] - 'a'));
            cd.collect_subtree(nxt, c, 1, nxt, aux0, vis, transition);
            for (auto &[node, mask_node] : temp) {
                int64_t match = count(mask_node, c);
                weight[node] += match;
                pair += match;
            }
            for (auto &[node, mask_node] : temp) {
                add(mask_node);
            }
        }
        int64_t matchC = count(bitc, c) - 1;
        weight[c] += matchC;
        nodes.clear();
        cd.build_parent_rooted(c, -1, nodes, parentTmp);
        cd.apply_path_to_centroid(
            nodes, parentTmp, weight,
            [&](int node, int64_t val) { ans[node] += val; });
        ans[c] -= pair;
        clear_freq();
    };
    cd.decompose(0, on_centroid);
    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " \n"[i == N - 1];
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
