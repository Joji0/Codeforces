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
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'

void solve() {
    // The idea to solve this problem is simply: if there are application with
    // a, b, c we take c to be minimum for every application for b, i.e., we are
    // searching for the minimum cost for anyone to take b as their subordinate.
    int n, m, hold = -1, start = -1;
    int64_t ans = 0;
    cin >> n;
    vector<int> q(n);
    vector<pair<int, int>> supervisor(n + 1, {-1, -1});
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        if (chmax(hold, q[i])) {
            start = i + 1;
        }
    }
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < supervisor[b].second || supervisor[b].second == -1) {
            supervisor[b] = {a, c};
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == start)
            continue;
        if (supervisor[i].first == -1) {
            // If there exists any employee which is not the boss and they
            // doesn't have any supervisor then such hierarchy is impossible to
            // build
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += supervisor[i].second * (i != start);
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
