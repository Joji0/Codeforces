#include <bits/stdc++.h>
using namespace std;

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
        for (auto &x : v) in >> x;
        return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
        for (auto &x : v) out << x << ' ';
        return out;
}
template <typename T> istream &operator>>(istream &in, vector<vector<T>> &vv) {
        for (auto &v : vv) in >> v;
        return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<vector<T>> &vv) {
        for (const auto &v : vv) out << v << '\n';
        return out;
}
template <typename T> void print(const vector<T> &v) {
        for (auto &x : v) cout << x << " ";
        cout << '\n';
}
template <typename T> void _print(const T &x) { cerr << x; }
template <typename T> void _print(const vector<T> &v) {
        cerr << '[';
        bool first = true;
        for (const auto &x : v) {
                if (!first) cerr << ", ";
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
                if (i + 1 < N) cerr << ", ";
        }
        cerr << "]";
}
template <typename T, size_t N> void _print(const T (&a)[N]) {
        cerr << "[";
        for (size_t i = 0; i < N; i++) {
                _print(a[i]);
                if (i + 1 < N) cerr << ", ";
        }
        cerr << "]";
}
template <typename T> void _print(const set<T> &s) {
        cerr << "{";
        bool first = true;
        for (auto &x : s) {
                if (!first) cerr << ", ";
                first = false;
                _print(x);
        }
        cerr << "}";
}
template <typename T> void _print(const multiset<T> &s) {
        cerr << "{";
        bool first = true;
        for (auto &x : s) {
                if (!first) cerr << ", ";
                first = false;
                _print(x);
        }
        cerr << "}";
}
template <typename K, typename V> void _print(const map<K, V> &m) {
        cerr << "{";
        bool first = true;
        for (auto &p : m) {
                if (!first) cerr << ", ";
                first = false;
                _print(p);
        }
        cerr << "}";
}
template <typename K, typename V> void _print(const unordered_map<K, V> &m) {
        cerr << "{";
        bool first = true;
        for (auto &p : m) {
                if (!first) cerr << ", ";
                first = false;
                _print(p);
        }
        cerr << "}";
}
template <typename T> void _print(const deque<T> &dq) {
        cerr << "dq(";
        for (int i = 0; i < dq.size(); i++) {
                _print(dq[i]);
                if (i + 1 < dq.size()) cerr << ", ";
        }
        cerr << ")";
}
template <typename T> void _print(queue<T> q) {
        cerr << "q(";
        bool first = true;
        while (!q.empty()) {
                if (!first) cerr << ", ";
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
                if (!first) cerr << ", ";
                first = false;
                _print(temp[i]);
        }
        cerr << ")";
}
template <typename T> void _print(priority_queue<T> pq) {
        cerr << "pq(";
        bool first = true;
        while (!pq.empty()) {
                if (!first) cerr << ", ";
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
                if (!first) cerr << ", ";
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
        for (auto &a : x) a += o;
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
template <typename T, typename... Args> void debug_impl(const char *names, T &&value, Args &&...args) {
        const char *comma = strchr(names, ',');
        cerr << CLR_BOLD << CLR_CYAN;
        cerr.write(names, comma - names);
        cerr << CLR_RESET << " = " << CLR_YELLOW;
        _print(value);
        cerr << CLR_RESET << " " << CLR_DIM << "| " << CLR_RESET;
        debug_impl(comma + 1, args...);
}
#ifndef ONLINE_JUDGE
#define IOJUDGE(title) freopen(title ".in", "r", stdin), freopen(title ".out", "w", stdout)
#else
#define IOJUDGE(title)
#endif
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
        template <class T> explicit y_combinator_result(T &&fun) : fun(std::forward<T>(fun)) {}

        template <class... Args> decltype(auto) operator()(Args &&...args) {
                return fun(std::ref(*this), std::forward<Args>(args)...);
        }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <class ElType, class N, class L> struct SegmentTree {
        int n = 0;
        mutable vector<N> t;
        mutable vector<L> lazy;
        N ID;
        L LID;
        function<N(const N &, const N &)> merge;
        function<N(const ElType &)> make;
        function<void(N &, const L &, int)> apply_node;
        function<void(L &, const L &)> compose;
        function<bool(const L &)> is_lazy_id;
        SegmentTree() {}
        SegmentTree(int n, N ID, L LID, function<N(const N &, const N &)> merge, function<N(const ElType &)> make,
                    function<void(N &, const L &, int)> apply_node, function<void(L &, const L &)> compose,
                    function<bool(const L &)> is_lazy_id) {
                init(n, ID, LID, merge, make, apply_node, compose, is_lazy_id);
        }
        void init(int n, N ID, L LID, function<N(const N &, const N &)> merge, function<N(const ElType &)> make,
                  function<void(N &, const L &, int)> apply_node, function<void(L &, const L &)> compose,
                  function<bool(const L &)> is_lazy_id) {
                this->n = n;
                this->ID = ID;
                this->LID = LID;
                this->merge = merge;
                this->make = make;
                this->apply_node = apply_node;
                this->compose = compose;
                this->is_lazy_id = is_lazy_id;
                assert(n > 0);
                t.assign(4 * n, ID);
                lazy.assign(4 * n, LID);
        }
        void build(const vector<ElType> &A, int v, int tl, int tr) {
                lazy[v] = LID;
                if (tl == tr) {
                        t[v] = make(A[tl]);
                } else {
                        int tm = (tl + tr) / 2;
                        build(A, v * 2, tl, tm);
                        build(A, v * 2 + 1, tm + 1, tr);
                        t[v] = merge(t[v * 2], t[v * 2 + 1]);
                }
        }
        void build(const vector<ElType> &A) {
                assert((int)A.size() == n);
                build(A, 1, 0, n - 1);
        }
        inline void apply(int v, int tl, int tr, const L &f) const {
                apply_node(t[v], f, tr - tl + 1);
                compose(lazy[v], f);
        }
        inline void push(int v, int tl, int tr) const {
                if (tl == tr) return;
                if (is_lazy_id(lazy[v])) return;
                int tm = (tl + tr) / 2;
                apply(v * 2, tl, tm, lazy[v]);
                apply(v * 2 + 1, tm + 1, tr, lazy[v]);
                lazy[v] = LID;
        }
        void update(int v, int tl, int tr, int l, int r, const L &f) const {
                if (l > r) return;
                if (l == tl && r == tr) {
                        apply(v, tl, tr, f);
                        return;
                }
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), f);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, f);
                t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
        void update(int l, int r, const L &f) const {
                assert(0 <= l && l <= r && r < n);
                update(1, 0, n - 1, l, r, f);
        }
        void update(int pos, const L &f) const {
                assert(0 <= pos && pos < n);
                update(1, 0, n - 1, pos, pos, f);
        }
        N query(int v, int tl, int tr, int l, int r) const {
                if (l > r) return ID;
                if (l == tl && r == tr) {
                        return t[v];
                }
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                return merge(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
        N query(int l, int r) const {
                assert(0 <= l && l <= r && r < n);
                return query(1, 0, n - 1, l, r);
        }
        N get(int pos) const { return query(pos, pos); }
        N all() const { return t[1]; }
        void set_point(int v, int tl, int tr, int pos, const ElType &new_val) const {
                if (tl == tr) {
                        lazy[v] = LID;
                        t[v] = make(new_val);
                        return;
                }
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                if (pos <= tm) {
                        set_point(v * 2, tl, tm, pos, new_val);
                } else {
                        set_point(v * 2 + 1, tm + 1, tr, pos, new_val);
                }
                t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
        void set_point(int pos, const ElType &new_val) const {
                assert(0 <= pos && pos < n);
                set_point(1, 0, n - 1, pos, new_val);
        }
        template <class Pred> int max_right(int l, int r, Pred pred) const {
                assert(0 <= l && l <= r && r < n);
                assert(pred(ID));
                N acc = ID;
                return max_right_dfs(1, 0, n - 1, l, r, pred, acc);
        }
        template <class Pred> int max_right_dfs(int v, int tl, int tr, int l, int r, Pred pred, N &acc) const {
                if (tr < l || tl > r) return l;
                if (tl >= l && tr <= r) {
                        N nxt = merge(acc, t[v]);
                        if (pred(nxt)) {
                                acc = nxt;
                                return tr + 1;
                        }
                        if (tl == tr) return tl;
                }
                if (tl == tr) return tl;
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                int res = max_right_dfs(v * 2, tl, tm, l, r, pred, acc);
                if (res <= tm) return res;
                return max_right_dfs(v * 2 + 1, tm + 1, tr, l, r, pred, acc);
        }
        template <class Pred> int max_right(int l, Pred pred) const {
                if (l == n) return n;
                return max_right(l, n - 1, pred);
        }
        template <class Pred> int min_left(int l, int r, Pred pred) const {
                assert(0 <= l && l <= r && r < n);
                assert(pred(ID));
                N acc = ID;
                return min_left_dfs(1, 0, n - 1, l, r, pred, acc);
        }
        template <class Pred> int min_left_dfs(int v, int tl, int tr, int l, int r, Pred pred, N &acc) const {
                if (tr < l || tl > r) return r + 1;
                if (tl >= l && tr <= r) {
                        N nxt = merge(t[v], acc);
                        if (pred(nxt)) {
                                acc = nxt;
                                return tl;
                        }
                        if (tl == tr) return tl + 1;
                }
                if (tl == tr) return tl + 1;
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                int res = min_left_dfs(v * 2 + 1, tm + 1, tr, l, r, pred, acc);
                if (res > tm + 1) return res;
                return min_left_dfs(v * 2, tl, tm, l, r, pred, acc);
        }
        template <class Pred> int min_left(int r, Pred pred) const {
                if (r < 0) return 0;
                return min_left(0, r, pred);
        }
};

const int LOG = 21;

void solve() {
        int N;
        cin >> N;
        vector<int64_t> A(N);
        cin >> A;
        struct Node {
                int64_t cnt[LOG];
                Node() { memset(cnt, 0, sizeof(cnt)); }
        };
        struct Lazy {
                int64_t mask;
                Lazy(int64_t m = 0) : mask(m) {}
        };
        Node ID = Node();
        Lazy LID(0);
        auto merge = [&](const Node &a, const Node &b) -> Node {
                Node ret;
                for (int i = 0; i < LOG; i++) {
                        ret.cnt[i] = a.cnt[i] + b.cnt[i];
                }
                return ret;
        };
        auto make = [&](const int64_t &a) -> Node {
                Node ret;
                for (int i = 0; i < LOG; i++) {
                        if ((1LL << i) & a) {
                                ret.cnt[i]++;
                        }
                }
                return ret;
        };
        auto apply_node = [&](Node &node, const Lazy &lazy, int rg) -> void {
                int mask = lazy.mask;
                for (int i = 0; i < LOG; i++) {
                        if (mask & (1LL << i)) {
                                node.cnt[i] = rg - node.cnt[i];
                        }
                }
        };
        auto compose_lazy = [&](Lazy &l, const Lazy &par) -> void { l.mask ^= par.mask; };
        auto is_lazy_id = [&](const Lazy &l) -> bool { return (l.mask == 0); };
        auto node_sum = [&](const Node &node) -> int64_t {
                int64_t ret = 0;
                for (int i = 0; i < LOG; i++) {
                        ret += 1LL * node.cnt[i] * (1LL << i);
                }
                return ret;
        };
        SegmentTree<int64_t, Node, Lazy> seg(N, ID, LID, merge, make, apply_node, compose_lazy, is_lazy_id);
        seg.build(A);
        int Q;
        cin >> Q;
        while (Q--) {
                int t;
                cin >> t;
                if (t == 1) {
                        int l, r;
                        cin >> l >> r;
                        l--, r--;
                        cout << node_sum(seg.query(l, r)) << '\n';
                } else {
                        int l, r;
                        int64_t x;
                        cin >> l >> r >> x;
                        l--, r--;
                        seg.update(l, r, Lazy(x));
                }
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
