#include <bits/stdc++.h>
using namespace std;

#define int int64_t

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

struct Fenwick {
    vector<int> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    Fenwick(vector<int> const &a) : Fenwick(a.size()) {
        for (int i = 0; i < (int)a.size(); i++) {
            add(i, a[i]);
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
        }
        return ret;
    }

    int sum(int l, int r) { return sum(r) - (l ? sum(l - 1) : 0); }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    cin >> a;
    vector<tuple<int, int, int>> operations(m);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        operations[i] = {l - 1, r - 1, d};
    }
    Fenwick opps(m + 5), fw(n + 5);
    while (k--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        opps.add(x, 1);
        opps.add(y + 1, -1);
    }
    for (int i = 0; i < m; i++) {
        auto [l, r, d] = operations[i];
        int cnt = opps.sum(i);
        fw.add(l, cnt * d);
        fw.add(r + 1, cnt * d * -1);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] + fw.sum(i) << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
