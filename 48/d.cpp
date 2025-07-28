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
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = {a[i], i};
    }
    sort(v.begin(), v.end());
    if (v.front().first != 1) {
        cout << "-1\n";
        return;
    }
    int cur = v[0].first, cnt = 1, last = 1e8;
    ans[v[0].second] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].first != cur) {
            cur = v[i].first;
            if (cnt > last || v[i - 1].first != v[i].first - 1) {
                cout << "-1\n";
                return;
            }
            last = cnt;
            cnt = 1;
            ans[v[i].second] = cnt;
        } else {
            cnt++;
            ans[v[i].second] = cnt;
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    print(ans);
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
