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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n), b(m);
    cin >> a >> b;
    sort(b.begin(), b.end());
    int64_t last = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = m - 1, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] - a[i] >= last) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // debug(last);
        if (res == -1) {
            if (a[i] >= last) {
                last = a[i];
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            if (a[i] < b[res] - a[i] && a[i] >= last) {
                last = a[i];
            } else {
                last = b[res] - a[i];
            }
        }
    }
    cout << "YES\n";
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
