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
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

// Classic BIT - Point Update + Range Query
template <typename T> struct FenwickSum {
    vector<T> bit;
    int n;

    FenwickSum(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickSum(const vector<T> &a) : FenwickSum(a.size()) {
        for (int i = 0; i < (int)a.size(); i++) {
            update(i, a[i]);
        }
    }

    // Point update at idx with delta with respect to a[idx]
    void update(int idx, T delta) {
        for (; idx < n; idx += (idx & -idx)) {
            bit[idx] += delta;
        }
    }

    // Prefix sum [1, r]
    T sum(int idx) {
        T ret = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // Range sum [l, r]
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

vt<int64_t> compr;
int c(int64_t val) { return lower_bound(all(compr), val) - compr.begin() + 1; }

void solve() {
    // The idea is to use 2 Fenwick tree and coordinate compression technique
    // (because a[i] can be up to 1e9). We fix an index j (2 <= j <= n - 1) and
    // iterate the array from left to right to check elements such that a[i] >
    // a[j] and a[j] > a[k]. We use the first Fenwick tree for indexes which are
    // to the left of j (i) and the second Fenwick tree for indexes which are to
    // the right of j (k). We initialize the first Fenwick tree as empty (since
    // we are starting our iteration from the left) and the second Fenwick tree
    // is initially full (include all a[x], 1 <= x <= n). After each iteration,
    // we do Ft2.update(a[j], -1) and update Ft1.update(a[j], 1) to simulate
    // "received" elements. The answer is then simply: the number of (a[i] >
    // a[j]) * the number of (a[j] > a[k]), this is because we can pair each
    // (a[i], a[j]) with any a[k] < a[j]. The final answer is then the sum of
    // this calculation over all j, 2 <= j <= n - 1.
    int n;
    cin >> n;
    vt<int> a(n + 1);
    FenwickSum<int64_t> Ft1(n + 1), Ft2(n + 1);
    FOR(i, 1, n + 1) {
        cin >> a[i];
        compr.push_back(a[i]);
    }
    // Coordinate compression
    sort(all(compr));
    compr.erase(unique(all(compr)), compr.end());
    // Initialize Ft2 with all elements of a
    FOR(i, 1, n + 1) { Ft2.update(c(a[i]), 1); }
    // Since we are starting from j = 2, we first update Ft1 with the first
    // element and "delete" it from Ft2
    Ft1.update(c(a[1]), 1);
    Ft2.update(c(a[1]), -1);
    Ft2.update(c(a[2]), -1);
    int64_t ans = 0;
    FOR(j, 2, n) {
        ans += Ft1.sum(c(a[j] + 1), c(compr.back())) *
               Ft2.sum(c(compr.front()), c(a[j] - 1));
        Ft1.update(c(a[j]), 1);
        Ft2.update(c(a[j + 1]), -1);
    }
    cout << ans << '\n';
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
