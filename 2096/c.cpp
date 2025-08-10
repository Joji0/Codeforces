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

const int64_t INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vt<vt<int64_t>> build(n, vt<int64_t>(n)), dprow(n + 1, vt<int64_t>(2, INF)),
        dpcol(n + 1, vt<int64_t>(2, INF));
    vt<int64_t> A(n), B(n);
    FOR(n) {
        FOR(j, n) { cin >> build[i][j]; }
    }
    cin >> A >> B;
    dprow[1][0] = 0;
    dprow[1][1] = A[0];
    FOR(i, 2, n + 1) {
        FOR(j, 2) {
            FOR(k, 2) {
                bool ok = true;
                FOR(it, n) {
                    int64_t u = build[i - 2][it] + k, d = build[i - 1][it] + j;
                    if (u == d) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    if (j) {
                        chmin(dprow[i][j], dprow[i - 1][k] + A[i - 1]);
                    } else {
                        chmin(dprow[i][j], dprow[i - 1][k]);
                    }
                }
            }
        }
    }
    dpcol[1][0] = 0;
    dpcol[1][1] = B[0];
    FOR(i, 2, n + 1) {
        FOR(j, 2) {
            FOR(k, 2) {
                bool ok = true;
                FOR(it, n) {
                    int64_t u = build[it][i - 2] + k, d = build[it][i - 1] + j;
                    if (u == d) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    if (j) {
                        chmin(dpcol[i][j], dpcol[i - 1][k] + B[i - 1]);
                    } else {
                        chmin(dpcol[i][j], dpcol[i - 1][k]);
                    }
                }
            }
        }
    }
    int64_t rowcost = min(dprow[n][0], dprow[n][1]),
            colcost = min(dpcol[n][0], dpcol[n][1]);
    if (rowcost == INF || colcost == INF) {
        cout << "-1\n";
        return;
    }
    cout << rowcost + colcost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
