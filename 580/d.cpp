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
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'
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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> a(n);
    vector<vector<int64_t>> b(n, vector<int64_t>(n));
    // define dp[mask][prev] as the maximum satisfaction after eating
    // __builtin_popcount(mask) dish with previous dish = prev.
    vector<vector<int64_t>> dp((1 << n), vector<int64_t>(n));
    cin >> a;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cin >> b[x][y];
    }
    for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = a[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int ate = __builtin_popcount(mask);
        if (ate >= m)
            continue;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)))
                continue;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j)) && i != j) {
                    chmax(dp[mask | (1 << j)][j], dp[mask][i] + a[j] + b[i][j]);
                }
            }
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != m)
            continue;
        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
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
