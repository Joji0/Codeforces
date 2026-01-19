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

template <int64_t MOD> struct ModInt {
        int64_t v;
        ModInt(int64_t _v = 0) {
                v = _v % MOD;
                if (v < 0) v += MOD;
        }
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
                v = (int64_t)v * o.v % MOD;
                return *this;
        }
        friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
        friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
        friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
        ModInt pow(int64_t e) const {
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
        friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
        friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
        explicit operator int() const { return (int)v; }
        explicit operator long long() const { return (long long)v; }
        friend ostream &operator<<(ostream &os, const ModInt &m) { return os << m.v; }
};

struct NTT {
        static constexpr int MOD = 998244353;
        static constexpr int G = 3;
        using mint = ModInt<MOD>;
        static int ceil_pow2(int x) {
                int n = 1;
                while (n < x) n <<= 1;
                return n;
        }
        static void ntt(vector<mint> &a, bool invert) {
                int n = (int)a.size();
                if (n == 1) return;
                static vector<int> rev;
                static vector<mint> roots{mint(0), mint(1)};
                static int last_n = 0;
                int lg = __builtin_ctz(n);
                if (n != last_n) {
                        last_n = n;
                        rev.assign(n, 0);
                        for (int i = 0; i < n; i++) {
                                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
                        }
                }
                for (int i = 0; i < n; i++) {
                        if (i < rev[i]) swap(a[i], a[rev[i]]);
                }
                if ((int)roots.size() < n) {
                        int k = __builtin_ctz((int)roots.size());
                        roots.resize(n);
                        while ((1 << k) < n) {
                                mint e = mint(G).pow((MOD - 1) >> (k + 1));
                                for (int i = 1 << (k - 1); i < (1 << k); i++) {
                                        roots[2 * i] = roots[i];
                                        roots[2 * i + 1] = roots[i] * e;
                                }
                                k++;
                        }
                }
                for (int len = 1; len < n; len <<= 1) {
                        for (int i = 0; i < n; i += 2 * len) {
                                for (int j = 0; j < len; j++) {
                                        mint u = a[i + j];
                                        mint v = a[i + j + len] * roots[len + j];
                                        a[i + j] = u + v;
                                        a[i + j + len] = u - v;
                                }
                        }
                }
                if (invert) {
                        reverse(a.begin() + 1, a.end());
                        mint inv_n = mint(n).inv();
                        for (auto &x : a) x *= inv_n;
                }
        }
        static vector<mint> convolution_mint(const vector<mint> &A, const vector<mint> &B) {
                if (A.empty() || B.empty()) return {};
                int n1 = (int)A.size(), n2 = (int)B.size();
                int need = n1 + n2 - 1;
                int n = ceil_pow2(need);
                vector<mint> fa(n), fb(n);
                for (int i = 0; i < n1; i++) fa[i] = A[i];
                for (int i = 0; i < n2; i++) fb[i] = B[i];
                ntt(fa, false);
                ntt(fb, false);
                for (int i = 0; i < n; i++) fa[i] *= fb[i];
                ntt(fa, true);
                fa.resize(need);
                return fa;
        }
        static vector<int> convolution(const vector<int> &A, const vector<int> &B) {
                if (A.empty() || B.empty()) return {};
                vector<mint> a(A.size()), b(B.size());
                for (int i = 0; i < (int)A.size(); i++) a[i] = mint(A[i]);
                for (int i = 0; i < (int)B.size(); i++) b[i] = mint(B[i]);
                auto c = convolution_mint(a, b);
                vector<int> res(c.size());
                for (int i = 0; i < (int)c.size(); i++) res[i] = (int)c[i].v;
                return res;
        }
};

using Mint = ModInt<998244353>;

void solve() {
        int N, K;
        cin >> N >> K;
        vector<int> Poly(10, 0);
        for (int i = 0; i < K; i++) {
                int x;
                cin >> x;
                Poly[x]++;
        }
        auto binary_convolution = [](vector<int> a, int b) -> vector<int> {
                vector<int> res = {1};
                while (b > 0) {
                        if (b & 1) {
                                res = NTT::convolution(res, a);
                        }
                        a = NTT::convolution(a, a);
                        b >>= 1;
                }
                return res;
        };
        vector<int> Polyy = binary_convolution(Poly, N / 2);
        Mint ans = 0;
        for (auto &x : Polyy) {
                ans += (Mint)x * (Mint)x;
        }
        cout << ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
