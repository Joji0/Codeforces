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

template <class ElType, class N> struct SegmentTree {
        int n;
        vector<N> t;
        N ID;
        function<N(const N &, const N &)> merge;
        function<N(const ElType &)> make;
        SegmentTree() : n(0) {}
        SegmentTree(int n, N ID, function<N(const N &, const N &)> merge, function<N(const ElType &)> make) {
                init(n, ID, merge, make);
        }
        void init(int n, N ID, function<N(const N &, const N &)> merge, function<N(const ElType &)> make) {
                this->n = n, this->ID = ID, this->merge = merge, this->make = make;
                assert(n > 0);
                t.assign(4 * n, ID);
        }
        void build(const vector<ElType> &A, int v, int tl, int tr) {
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
        N query(int v, int tl, int tr, int l, int r) const {
                if (l > r) return ID;
                if (l == tl && r == tr) return t[v];
                int tm = (tl + tr) / 2;
                return merge(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
        N query(int l, int r) const { return query(1, 0, n - 1, l, r); }
        N get(int pos) const { return query(pos, pos); }
        N all() const { return t[1]; }
        void update(int v, int tl, int tr, int pos, const ElType &new_val) {
                if (tl == tr) {
                        t[v] = make(new_val);
                } else {
                        int tm = (tl + tr) / 2;
                        if (pos <= tm)
                                update(v * 2, tl, tm, pos, new_val);
                        else
                                update(v * 2 + 1, tm + 1, tr, pos, new_val);
                        t[v] = merge(t[v * 2], t[v * 2 + 1]);
                }
        }
        void update(int pos, const ElType &new_val) { update(1, 0, n - 1, pos, new_val); }
        template <class F> void modify(int v, int tl, int tr, int pos, F &&f) {
                if (tl == tr) {
                        t[v] = f(t[v]);
                } else {
                        int tm = (tl + tr) / 2;
                        if (pos <= tm)
                                modify(v * 2, tl, tm, pos, std::forward<F>(f));
                        else
                                modify(v * 2 + 1, tm + 1, tr, pos, std::forward<F>(f));
                        t[v] = merge(t[v * 2], t[v * 2 + 1]);
                }
        }
        template <class F> void modify(int pos, F &&f) { modify(1, 0, n - 1, pos, std::forward<F>(f)); }
        template <class Pred> int max_right(int l, Pred pred) const {
                assert(0 <= l && l <= n);
                assert(pred(ID));
                N acc = ID;
                return max_right_dfs(1, 0, n - 1, l, pred, acc);
        }
        template <class Pred> int max_right_dfs(int v, int tl, int tr, int l, Pred pred, N &acc) const {
                if (tr < l) return l;
                if (tl >= l) {
                        N nxt = merge(acc, t[v]);
                        if (pred(nxt)) {
                                acc = nxt;
                                return tr + 1;
                        }
                        if (tl == tr) {
                                return tl;
                        }
                }
                if (tl == tr) return tl;
                int tm = (tl + tr) / 2;
                int res = max_right_dfs(v * 2, tl, tm, l, pred, acc);
                if (res <= tm) return res;
                return max_right_dfs(v * 2 + 1, tm + 1, tr, l, pred, acc);
        }
        template <class Pred> int min_left(int r, Pred pred) const {
                assert(0 <= r && r <= n);
                assert(pred(ID));
                N acc = ID;
                return min_left_dfs(1, 0, n - 1, r, pred, acc);
        }
        template <class Pred> int min_left_dfs(int v, int tl, int tr, int r, Pred pred, N &acc) const {
                if (tl >= r) return r;
                if (tr < r) {
                        N nxt = merge(t[v], acc);
                        if (pred(nxt)) {
                                acc = nxt;
                                return tl;
                        }
                        if (tl == tr) {
                                return tl + 1;
                        }
                }
                if (tl == tr) return tl + 1;
                int tm = (tl + tr) / 2;
                int res = min_left_dfs(v * 2 + 1, tm + 1, tr, r, pred, acc);
                if (res > tm + 1) return res;
                return min_left_dfs(v * 2, tl, tm, r, pred, acc);
        }
};

const long double PI = acos(-1);

void solve() {
        int N;
        cin >> N;
        int64_t r, h;
        vector<int64_t> vols(N);
        for (int i = 0; i < N; i++) {
                cin >> r >> h;
                vols[i] = r * r * h;
        }
        vector<int64_t> compressed = vols;
        sort(compressed.begin(), compressed.end());
        compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
        int M = compressed.size();
        auto merge = [&](const int64_t &a, const int64_t &b) -> int64_t { return max(a, b); };
        auto make = [&](const int64_t &a) -> int64_t { return a; };
        int64_t ans = 0.0;
        SegmentTree<int64_t, int64_t> seg(M + 67, 0, merge, make);
        seg.build(vector<int64_t>(M + 67, 0));
        auto get = [&](int idx) -> int {
                return lower_bound(compressed.begin(), compressed.end(), vols[idx]) - compressed.begin();
        };
        for (int i = 0; i < N; i++) {
                int place = get(i);
                int64_t mx = place ? seg.query(0, place - 1) : 0, now = mx + vols[i];
                seg.update(place, now);
                chmax(ans, now);
        }
        cout << fixed << setprecision(15) << PI * ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
