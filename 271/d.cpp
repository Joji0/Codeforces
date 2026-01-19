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
    for (auto &x : v) {
        cout << x << " ";
    }
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
template <typename T> void offset(int64_t o, vector<T> &x) {
    for (auto &a : x) {
        a += o;
    }
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
#ifndef ONLINE_JUDGE
#define IOJUDGE(title)                                                         \
    freopen(title ".in", "r", stdin), freopen(title ".out", "w", stdout)
#else
#define IOJUDGE(title)
#endif
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define LL(x) static_cast<int64_t>(x)
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

int k;
set<char> oks;

struct StringHash {
    const int64_t base = 31;
    const int64_t mod = 1e9 + 9;
    int n;
    vt<int64_t> h, p, inv_p, prefBad;
    string s;

    static int64_t modpow(int64_t a, int64_t e, int64_t m) {
        int64_t r = 1;
        while (e) {
            if (e & 1)
                r = (r * a) % m;
            a = (a * a) % m;
            e >>= 1;
        }
        return r;
    }

    StringHash(const string &_s) {
        s = _s;
        n = sz(s);
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        inv_p.assign(n + 1, 1);
        prefBad.assign(n + 1, 0);
        FOR(i, 1, n + 1) { p[i] = (p[i - 1] * base) % mod; }
        inv_p[n] = modpow(p[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; i--)
            inv_p[i] = (inv_p[i + 1] * base) % mod;
        FOR(i, 0, n) { h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p[i]) % mod; }
        FOR(i, 0, n) { prefBad[i + 1] = prefBad[i] + (!oks.contains(s[i])); }
    }

    int64_t get(int l, int r) const {
        if (l > r)
            return 0;
        int64_t val = (h[r + 1] - h[l] + mod) % mod;
        return (val * inv_p[l]) % mod;
    }

    bool equal(int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (len1 != len2)
            return false;
        return get(l1, r1) == get(l2, r2);
    }

    int64_t calc() {
        int64_t ret = 0;
        FOR(len, 1, n + 1) {
            unordered_set<int64_t> st;
            FOR(i, 0, n - len + 1) {
                if (prefBad[i + len] - prefBad[i] > k)
                    continue;
                int64_t cur = get(i, i + len - 1);
                st.insert(cur);
            }
            ret += sz(st);
        }
        return ret;
    }
};

void solve() {
    string s, ok;
    cin >> s >> ok >> k;
    FOR(26) {
        if (ok[i] == '1') {
            char ch = 'a' + i;
            oks.insert(ch);
        }
    }
    StringHash SH(s);
    cout << SH.calc() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
