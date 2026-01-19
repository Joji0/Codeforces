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

struct Trie {
    static constexpr int MAXCHAR = 26;
    struct Node {
        array<int, MAXCHAR> nxt;
        int pass, end;
        Node() {
            nxt.fill(-1);
            pass = 0;
            end = 0;
        }
    };
    vector<Node> t;
    Trie(int reserve_nodes = 0) { init(reserve_nodes); }
    void init(int reserve_nodes = 0) {
        t.clear();
        if (reserve_nodes > 0)
            t.reserve(reserve_nodes);
        t.push_back(Node());
    }
    int root() const { return 0; }
    int size() const { return (int)t.size(); }
    int insert(const string &s) {
        int v = 0;
        t[v].pass++;
        for (char c : s) {
            int id = c - 'a';
            if (t[v].nxt[id] == -1) {
                t[v].nxt[id] = (int)t.size();
                t.push_back(Node());
            }
            v = t[v].nxt[id];
            t[v].pass++;
        }
        t[v].end++;
        return v;
    }
    int go(const string &p) const {
        int v = 0;
        for (char c : p) {
            int id = c - 'a';
            if (t[v].nxt[id] == -1)
                return -1;
            v = t[v].nxt[id];
        }
        return v;
    }
    bool starts_with(const string &p) const { return go(p) != -1; }
    int count_word(const string &s) const {
        int v = go(s);
        return (v == -1 ? 0 : t[v].end);
    }
    int count_prefix(const string &p) const {
        int v = go(p);
        return (v == -1 ? 0 : t[v].pass);
    }
    bool exists(const string &s) const { return count_word(s) > 0; }
    bool erase(const string &s) {
        if (!count_word(s))
            return false;
        int v = 0;
        t[v].pass--;
        for (char c : s) {
            int id = c - 'a';
            int u = t[v].nxt[id];
            v = u;
            t[v].pass--;
        }
        t[v].end--;
        return true;
    }
    int count_subtree_words(int v) const {
        int total = 0;
        stack<int> st;
        st.push(v);
        while (!st.empty()) {
            int x = st.top();
            st.pop();
            total += t[x].end;
            for (int c = 0; c < 26; c++) {
                int u = t[x].nxt[c];
                if (u != -1)
                    st.push(u);
            }
        }
        return total;
    }
    bool erase_prefix(const string &p) {
        int v = 0;
        vector<int> path;
        path.reserve(p.size() + 1);
        path.push_back(0);
        for (char c : p) {
            int id = c - 'a';
            int u = t[v].nxt[id];
            if (u == -1)
                return false;
            v = u;
            path.push_back(v);
        }
        vector<int> nodes;
        nodes.reserve(64);
        stack<int> st;
        st.push(v);
        while (!st.empty()) {
            int x = st.top();
            st.pop();
            nodes.push_back(x);
            for (int c = 0; c < MAXCHAR; c++) {
                int u = t[x].nxt[c];
                if (u != -1)
                    st.push(u);
            }
        }
        int total = 0;
        for (int x : nodes)
            total += t[x].end;
        if (total == 0)
            return false;
        for (int node : path)
            t[node].pass -= total;
        if ((int)path.size() >= 2) {
            int par = path[(int)path.size() - 2];
            int child = path.back();
            for (int c = 0; c < MAXCHAR; c++) {
                if (t[par].nxt[c] == child) {
                    t[par].nxt[c] = -1;
                    break;
                }
            }
        }
        for (int x : nodes) {
            t[x].pass = 0;
            t[x].end = 0;
            t[x].nxt.fill(-1);
        }
        return true;
    }
};

void solve() {
    int N;
    cin >> N;
    Trie trie(1 << 20);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    vector<int> depth(trie.size() + 67);
    auto get_depth = y_combinator([&](auto self, int node) -> void {
        for (auto &nxt : trie.t[node].nxt) {
            if (nxt != -1) {
                depth[nxt] = depth[node] + 1;
                self(nxt);
            }
        }
    });
    get_depth(0);
    auto small_to_large = [&](multiset<int> &a, multiset<int> &b) -> void {
        if ((int)a.size() < (int)b.size())
            swap(a, b);
        for (auto &x : b) {
            a.insert(x);
        }
    };
    auto dfs = y_combinator([&](auto self, int node) -> multiset<int> {
        multiset<int> now;
        for (auto &nxt : trie.t[node].nxt) {
            if (nxt != -1) {
                multiset<int> got = self(nxt);
                small_to_large(now, got);
            }
        }
        if (trie.t[node].end) {
            now.insert(depth[node]);
        }
        if (node != trie.root() && trie.t[node].end == 0 && !now.empty()) {
            now.insert(depth[node]);
            auto it = prev(now.end());
            now.erase(it);
        }
        return now;
    });
    multiset<int> f = dfs(0);
    int64_t ans = 0;
    for (auto &x : f) {
        ans += 1LL * x;
    }
    cout << ans << '\n';
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
