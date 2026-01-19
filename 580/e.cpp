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

struct RH {
        static const int MOD1 = 1000000007;
        static const int MOD2 = 1000000009;
        static const int BASE = 911382323;
        struct H {
                int a, b;
                H(int _a = 0, int _b = 0) : a(_a), b(_b) {}
                bool operator==(const H &o) const { return a == o.a && b == o.b; }
                bool operator!=(const H &o) const { return !(*this == o); }
        };
        int n = 0;
        vector<int> p1, p2;
        vector<int> ip1, ip2;
        vector<int> ones1, ones2;
        vector<H> pref;
        RH() {}
        RH(int max_n) {
                init_tables(max_n);
                init_inv_tables();
        }
        static inline int addmod(int x, int y, int mod) {
                x += y;
                if (x >= mod) x -= mod;
                return x;
        }
        static inline int submod(int x, int y, int mod) {
                x -= y;
                if (x < 0) x += mod;
                return x;
        }
        static inline int mulmod(int64_t x, int64_t y, int mod) { return (int)(x * y % mod); }
        static int modpow(int a, int e, int mod) {
                int64_t r = 1, x = a;
                while (e > 0) {
                        if (e & 1) r = r * x % mod;
                        x = x * x % mod;
                        e >>= 1;
                }
                return (int)r;
        }
        void init_tables(int max_n) {
                n = max_n;
                assert(n >= 0);
                p1.assign(n + 1, 1);
                p2.assign(n + 1, 1);
                ones1.assign(n + 1, 0);
                ones2.assign(n + 1, 0);
                for (int i = 1; i <= n; i++) {
                        p1[i] = mulmod(p1[i - 1], BASE, MOD1);
                        p2[i] = mulmod(p2[i - 1], BASE, MOD2);
                }
                for (int i = 1; i <= n; i++) {
                        ones1[i] = addmod(ones1[i - 1], p1[i - 1], MOD1);
                        ones2[i] = addmod(ones2[i - 1], p2[i - 1], MOD2);
                }
        }
        void init_inv_tables() {
                assert(n >= 0);
                ip1.assign(n + 1, 1);
                ip2.assign(n + 1, 1);
                int invB1 = modpow(BASE, MOD1 - 2, MOD1);
                int invB2 = modpow(BASE, MOD2 - 2, MOD2);
                for (int i = 1; i <= n; i++) {
                        ip1[i] = mulmod(ip1[i - 1], invB1, MOD1);
                        ip2[i] = mulmod(ip2[i - 1], invB2, MOD2);
                }
        }
        H repeat(int x, int len) const {
                assert(0 <= len && len <= n);
                return H(mulmod(x, ones1[len], MOD1), mulmod(x, ones2[len], MOD2));
        }
        H shift(const H &A, int k) const {
                assert(0 <= k && k <= n);
                return H(mulmod(A.a, p1[k], MOD1), mulmod(A.b, p2[k], MOD2));
        }
        H concat(const H &A, int lenA, const H &B, int lenB) const {
                assert(0 <= lenA && 0 <= lenB && lenA + lenB <= n);
                int na = addmod(A.a, mulmod(B.a, p1[lenA], MOD1), MOD1);
                int nb = addmod(A.b, mulmod(B.b, p2[lenA], MOD2), MOD2);
                return H(na, nb);
        }
        template <class F> void build_from_string(const string &s, F map_char) {
                int m = (int)s.size();
                assert(m <= n);
                pref.assign(m + 1, H(0, 0));
                for (int i = 0; i < m; i++) {
                        int x = map_char(s[i]);
                        pref[i + 1].a = addmod(pref[i].a, mulmod(x, p1[i], MOD1), MOD1);
                        pref[i + 1].b = addmod(pref[i].b, mulmod(x, p2[i], MOD2), MOD2);
                }
        }
        void build_from_digits(const string &s) {
                build_from_string(s, [&](char c) { return (c - '0') + 1; });
        }
        void build_from_lowercase(const string &s) {
                build_from_string(s, [&](char c) { return (c - 'a') + 1; });
        }
        void build_from_array(const vector<int> &a) {
                int m = (int)a.size();
                assert(m <= n);
                pref.assign(m + 1, H(0, 0));
                for (int i = 0; i < m; i++) {
                        int x = a[i];
                        pref[i + 1].a = addmod(pref[i].a, mulmod(x, p1[i], MOD1), MOD1);
                        pref[i + 1].b = addmod(pref[i].b, mulmod(x, p2[i], MOD2), MOD2);
                }
        }
        H get_raw(int l, int r) const {
                if (l > r) return H(0, 0);
                int ra = submod(pref[r + 1].a, pref[l].a, MOD1);
                int rb = submod(pref[r + 1].b, pref[l].b, MOD2);
                return H(ra, rb);
        }
        H get_norm(int l, int r) const {
                if (l > r) return H(0, 0);
                assert(!ip1.empty());
                int ra = submod(pref[r + 1].a, pref[l].a, MOD1);
                int rb = submod(pref[r + 1].b, pref[l].b, MOD2);
                ra = mulmod(ra, ip1[l], MOD1);
                rb = mulmod(rb, ip2[l], MOD2);
                return H(ra, rb);
        }
        H get(int l, int r) const { return get_norm(l, r); }
        int lcp(int i, int j, int limit) const {
                if (limit <= 0) return 0;
                int lo = 0, hi = limit;
                while (lo < hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (get(i, i + mid - 1) == get(j, j + mid - 1))
                                lo = mid;
                        else
                                hi = mid - 1;
                }
                return lo;
        }
        template <class GetVal> int cmp_substr(int i, int j, int len, GetVal get_val) const {
                if (len <= 0) return 0;
                int x = lcp(i, j, len);
                if (x == len) return 0;
                int vi = get_val(i + x);
                int vj = get_val(j + x);
                if (vi < vj) return -1;
                if (vi > vj) return +1;
                return 0;
        }
};

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

void solve() {
        int N, M, K;
        string s;
        cin >> N >> M >> K >> s;
        RH rh(N);
        vector<int64_t> A(N);
        for (int i = 0; i < N; i++) {
                A[i] = (s[i] - '0') + 1;
        }
        struct Node {
                RH::H hash;
                int len;
        };
        struct Lazy {
                int v;
                Lazy(int _v = -1) : v(_v) {}
        };
        Node ID = Node({RH::H(0, 0), 0});
        Lazy LID = Lazy();
        auto merge = [&](const Node &a, const Node &b) -> Node {
                Node ret;
                ret.hash = rh.concat(a.hash, a.len, b.hash, b.len);
                ret.len = a.len + b.len;
                return ret;
        };
        auto make = [&](const int64_t &x) -> Node { return Node({rh.repeat(x, 1), 1}); };
        auto apply_node = [&](Node &node, const Lazy &lazy, int rg) -> void {
                if (lazy.v == -1) return;
                node.hash = rh.repeat(lazy.v, node.len);
        };
        auto compose = [&](Lazy &now, const Lazy &par) -> void {
                if (par.v != -1) now.v = par.v;
        };
        auto is_lazy_id = [&](const Lazy &lazy) -> bool { return lazy.v == -1; };
        SegmentTree<int64_t, Node, Lazy> seg(N, ID, LID, merge, make, apply_node, compose, is_lazy_id);
        seg.build(A);
        int Q = M + K;
        while (Q--) {
                int t;
                cin >> t;
                if (t == 1) {
                        int l, r, c;
                        cin >> l >> r >> c;
                        l--, r--;
                        c++;
                        seg.update(l, r, Lazy(c));
                } else {
                        int l, r, d;
                        cin >> l >> r >> d;
                        l--, r--;
                        int len = r - l + 1;
                        if (d == len) {
                                cout << "YES\n";
                                continue;
                        }
                        if (seg.query(l, r - d).hash == seg.query(l + d, r).hash) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
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
