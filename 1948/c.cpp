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

const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void solve() {
    int n;
    cin >> n;
    vt<vt<char>> grid(2, vt<char>(n));
    vt<vt<int64_t>> vis(2, vt<int64_t>(n, 0));
    FOR(2) {
        FOR(j, n) { cin >> grid[i][j]; }
    }
    queue<array<int64_t, 2>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        FOR(4) {
            int64_t nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < n && !vis[nx][ny]) {
                if (grid[nx][ny] == '>' && ny + 1 < n && !vis[nx][ny + 1]) {
                    q.push({nx, ny + 1});
                    vis[nx][ny + 1] = true;
                } else if (ny - 1 >= 0 && !vis[nx][ny - 1]) {
                    q.push({nx, ny - 1});
                    vis[nx][ny - 1] = true;
                }
            }
        }
    }
    cout << (vis[1][n - 1] ? "YES\n" : "NO\n");
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
