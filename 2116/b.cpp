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

const int maxN = 100005;
const int64_t MOD = 998244353;
vt<int64_t> pow2(maxN, 0);

void solve() {
    int n;
    cin >> n;
    vt<int64_t> P(n), Q(n);
    cin >> P >> Q;
    vt<array<int64_t, 2>> R(n), prefP(n), prefQ(n);
    prefP[0][0] = P[0];
    prefP[0][1] = 0;
    prefQ[0][0] = Q[0];
    prefQ[0][1] = 0;
    FOR(i, 1, n) {
        if (P[i] > prefP[i - 1][0]) {
            prefP[i][0] = P[i];
            prefP[i][1] = i;
        } else {
            prefP[i][0] = prefP[i - 1][0];
            prefP[i][1] = prefP[i - 1][1];
        }
    }
    FOR(i, 1, n) {
        if (Q[i] > prefQ[i - 1][0]) {
            prefQ[i][0] = Q[i];
            prefQ[i][1] = i;
        } else {
            prefQ[i][0] = prefQ[i - 1][0];
            prefQ[i][1] = prefQ[i - 1][1];
        }
    }
    FOR(n) {
        int64_t arg1 = prefP[i][1], arg2 = prefQ[i][1];
        int64_t a1 = P[arg1], b1 = Q[i - arg1], a2 = P[i - arg2], b2 = Q[arg2];
        int64_t M1 = max(a1, b1), S1 = min(a1, b1), M2 = max(a2, b2),
                S2 = min(a2, b2);
        int64_t M, S;
        if (M1 > M2) {
            M = M1;
            S = S1;
        } else if (M2 > M1) {
            M = M2;
            S = S2;
        } else {
            M = M1;
            S = max(S1, S2);
        }
        cout << (pow2[M] + pow2[S]) % MOD << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pow2[0] = 1;
    FOR(i, 1, maxN) { pow2[i] = (pow2[i - 1] * 2) % MOD; }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
