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
template <class T> void offset(int64_t o, vector<T> &x) {
    for (auto &a : x) {
        a += o;
    }
}
#define debug(x)                                                               \
    cerr << #x << " = ";                                                       \
    _print(x);                                                                 \
    cerr << '\n'
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vt vector
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

struct Fenwick {
    vector<int64_t> bit;
    int n;

    Fenwick(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    Fenwick(vector<int64_t> a) : Fenwick(a.size()) {
        for (int i = 0; i < (int)a.size(); i++) {
            upd(i, a[i]);
        }
    }

    int64_t sum(int idx) {
        int64_t ret = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    int64_t sum(int l, int r) { return sum(r) - sum(l - 1); }

    void upd(int idx, int64_t delta) {
        for (; idx < n; idx += (idx & -idx)) {
            bit[idx] += delta;
        }
    }
};

void solve() {
    // The idea here is to use Fenwick tree for the + and - queries. For the (s)
    // query, we can use 10 Fenwick tree to easily determine the sum of each
    // mod (this can be implemented by making vector of Fenwick trees).
    int n, m;
    cin >> n >> m;
    vt<Fenwick> Ft(m + 1, Fenwick(n + 1));
    vt<int> a(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];
    FOR(i, 1, n + 1) {
        int mod = a[i] % m;
        Ft[mod].upd(i, a[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        int64_t p, l, r, modulo;
        if (type == '+' || type == '-') {
            cin >> p >> r;
            int64_t get = a[p];
            Ft[get % m].upd(p, -get);
            if (type == '+') {
                get += r;
            } else if (r <= get) {
                get -= r;
            }
            a[p] = get;
            cout << get << '\n';
            int place = get % m;
            Ft[place].upd(p, get);
        } else {
            cin >> l >> r >> modulo;
            int64_t s = Ft[modulo].sum(l, r);
            cout << s << '\n';
        }
    }
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
