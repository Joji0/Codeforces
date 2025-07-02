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
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'

// This is bad solution as I was lucky to get away with 1 ms from the 2 s time
// limit lol
void solve() {
    int n, m;
    int64_t ans = 0;
    cin >> n >> m;
    // define dp[mask][v] as number of simple cycle up to vertex v with visited
    // status as mask (1 = visited, 0 = not yet)
    vector<vector<int64_t>> dp((1 << n), vector<int64_t>(n));
    vector<vector<bool>> matrix(n, vector<bool>(n));
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        matrix[u][v] = matrix[v][u] = 1;
    }
    for (int start = 0; start < n;
         start++) { // try every vertex as the starting point
        for (int i = 0; i < (1 << n); i++) {
            fill(dp[i].begin(), dp[i].end(), 0);
        }
        dp[1 << start][start] = 1;
        for (int mask = 1; mask < (1 << n); mask++) { // mask (1 = visited)
            if ((mask & ((1 << start) - 1)) != 0) {
                // avoid overcalculating vertex smaller than start
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) // havent reach this vertex yet
                    continue;
                for (int k = 0; k < n; k++) { // try every vertex k from j
                    if (!(mask & (1 << k)) && matrix[j][k] && k > start) {
                        dp[mask | (1 << k)][k] += dp[mask][j];
                    }
                }
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) < 3)
                continue; // validate only simple cycle
            for (int j = 0; j < n; j++) {
                if (i & (1 << j) && matrix[j][start]) {
                    ans += dp[i][j];
                }
            }
        }
    }
    cout << ans / 2 << '\n';
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
