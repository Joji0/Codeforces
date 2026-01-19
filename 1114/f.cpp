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

template <int64_t MOD_> struct ModInt {
        static_assert(MOD_ > 1, "MOD must be > 1");
        static constexpr int64_t MOD = MOD_;
        int64_t v;
        ModInt() : v(0) {}
        ModInt(int64_t x) { v = norm(x); }
        static inline int64_t norm(int64_t x) {
                x %= MOD;
                if (x < 0) x += MOD;
                return x;
        }
        static constexpr int64_t mod() { return MOD; }
        int64_t val() const { return v; }
        ModInt &operator+=(const ModInt &o) {
                v += o.v;
                if (v >= MOD) v -= MOD;
                return *this;
        }
        ModInt &operator-=(const ModInt &o) {
                v -= o.v;
                if (v < 0) v += MOD;
                return *this;
        }
        ModInt &operator*=(const ModInt &o) {
                v = (int64_t)((__int128)v * o.v % MOD);
                return *this;
        }
        friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
        friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
        friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
        ModInt operator-() const { return ModInt(v == 0 ? 0 : MOD - v); }
        friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
        friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
        friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
        friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
        ModInt &operator++() {
                v++;
                if (v >= MOD) v -= MOD;
                return *this;
        }
        ModInt &operator--() {
                v--;
                if (v < 0) v += MOD;
                return *this;
        }
        ModInt operator++(int) {
                ModInt tmp = *this;
                ++(*this);
                return tmp;
        }
        ModInt operator--(int) {
                ModInt tmp = *this;
                --(*this);
                return tmp;
        }
        ModInt pow(int64_t e) const {
                if (e < 0) return inv().pow(-e);
                ModInt r = 1, a = *this;
                while (e > 0) {
                        if (e & 1) r *= a;
                        a *= a;
                        e >>= 1;
                }
                return r;
        }
        ModInt inv() const { return pow(MOD - 2); }
        ModInt &operator/=(const ModInt &o) { return *this *= o.inv(); }
        friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
        explicit operator int() const { return (int)v; }
        explicit operator int64_t() const { return (int64_t)v; }
        friend ostream &operator<<(ostream &os, const ModInt &m) { return os << m.v; }
        friend istream &operator>>(istream &is, ModInt &m) {
                int64_t x;
                is >> x;
                m = ModInt(x);
                return is;
        }
};

using Mint = ModInt<1000000007>;
const int maxN = 301;

bool prime[maxN];
vector<int> primes;
uint64_t prime_mask[maxN];
Mint inv_cache[maxN];

void precompute() {
        fill(prime, prime + maxN, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i < maxN; i++) {
                if (prime[i]) {
                        for (int j = i * i; j < maxN; j += i) {
                                prime[j] = false;
                        }
                }
        }
        for (int i = 2; i < maxN; i++) {
                if (prime[i]) primes.push_back(i);
        }
        fill(prime_mask, prime_mask + maxN, 0);
        for (int i = 1; i < maxN; i++) {
                int n = i;
                for (int j = 0; j < (int)primes.size(); j++) {
                        if (primes[j] * primes[j] > n) break;
                        if (n % primes[j] == 0) {
                                prime_mask[i] |= (1ULL << j);
                                while (n % primes[j] == 0) n /= primes[j];
                        }
                }
                if (n > 1) {
                        int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
                        prime_mask[i] |= (1ULL << idx);
                }
        }
        for (int i = 0; i < (int)primes.size(); i++) {
                inv_cache[i] = Mint(primes[i]).inv();
        }
}

struct Node {
        uint64_t mask;
        Mint prod;
        Node() : mask(0), prod(1) {}
        Node(int n) : mask(prime_mask[n]), prod(n) {}
};

struct Lazy {
        Mint x;
        uint64_t lazy_mask;
        Lazy() : x(1), lazy_mask(0) {}
        Lazy(int n) : x(n), lazy_mask(prime_mask[n]) {}
};

struct SegmentTree {
        int n;
        vector<Node> t;
        vector<Lazy> lazy;
        SegmentTree(int n) : n(n), t(4 * n), lazy(4 * n) {}
        void build(const vector<int> &A, int v, int tl, int tr) {
                if (tl == tr) {
                        t[v] = Node(A[tl]);
                } else {
                        int tm = (tl + tr) / 2;
                        build(A, v * 2, tl, tm);
                        build(A, v * 2 + 1, tm + 1, tr);
                        t[v].mask = t[v * 2].mask | t[v * 2 + 1].mask;
                        t[v].prod = t[v * 2].prod * t[v * 2 + 1].prod;
                }
        }
        void apply(int v, int tl, int tr, const Lazy &f) {
                t[v].mask |= f.lazy_mask;
                t[v].prod *= f.x.pow(tr - tl + 1);
                lazy[v].x *= f.x;
                lazy[v].lazy_mask |= f.lazy_mask;
        }
        void push(int v, int tl, int tr) {
                if (lazy[v].x == Mint(1) && lazy[v].lazy_mask == 0) return;
                int tm = (tl + tr) / 2;
                apply(v * 2, tl, tm, lazy[v]);
                apply(v * 2 + 1, tm + 1, tr, lazy[v]);
                lazy[v] = Lazy();
        }
        void update(int v, int tl, int tr, int l, int r, const Lazy &f) {
                if (l > r) return;
                if (l == tl && r == tr) {
                        apply(v, tl, tr, f);
                        return;
                }
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), f);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, f);
                t[v].mask = t[v * 2].mask | t[v * 2 + 1].mask;
                t[v].prod = t[v * 2].prod * t[v * 2 + 1].prod;
        }
        Node query(int v, int tl, int tr, int l, int r) {
                if (l > r) return Node();
                if (l == tl && r == tr) return t[v];
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                Node left = query(v * 2, tl, tm, l, min(r, tm));
                Node right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
                Node res;
                res.mask = left.mask | right.mask;
                res.prod = left.prod * right.prod;
                return res;
        }
};

void solve() {
        precompute();
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        SegmentTree seg(N);
        seg.build(A, 1, 0, N - 1);
        while (Q--) {
                string t;
                cin >> t;
                if (t == "TOTIENT") {
                        int l, r;
                        cin >> l >> r;
                        l--, r--;
                        Node got = seg.query(1, 0, N - 1, l, r);
                        Mint ans = got.prod;
                        for (int i = 0; i < (int)primes.size(); i++) {
                                if ((1ULL << i) & got.mask) {
                                        ans *= Mint(primes[i] - 1) * inv_cache[i];
                                }
                        }
                        cout << ans << '\n';
                } else {
                        int l, r, x;
                        cin >> l >> r >> x;
                        l--, r--;
                        seg.update(1, 0, N - 1, l, r, Lazy(x));
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
