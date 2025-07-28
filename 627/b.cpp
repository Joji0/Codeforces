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

// Classic BIT - Point Update + Range Query
template <typename T> struct FenwickSum {
    vector<T> bit;
    int n;

    FenwickSum(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickSum(const vector<T> &a) : FenwickSum(a.size()) {
        for (int i = 0; i < (int)a.size(); i++) {
            update(i, a[i]);
        }
    }

    // Point update at idx with delta with respect to a[idx]
    void update(int idx, T delta) {
        for (; idx < n; idx += (idx & -idx)) {
            bit[idx] += delta;
        }
    }

    // Prefix sum [1, r]
    T sum(int idx) {
        T ret = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // Range sum [l, r]
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

void solve() {
    // For each query of type 1, we do a point update on Fenwick tree. We update
    // if and only if after the update, the point is still <= a or <= b (to make
    // sure that we can do only at most a or b orders). Hence we need 2 Fenwick
    // tree (one is when we use b production from day 1 to p and the other is
    // for when we use a production from day p + k to n). For each query of type
    // 2, we do a range sum over [1, p] from the first Fenwick tree and
    // adding range sum over [p + k, n] from the second Fenwick tree.
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    FenwickSum<int64_t> Fta(n + 1), Ftb(n + 1);
    int64_t arr1[200005], arr2[200005];
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int d, ord;
            cin >> d >> ord;
            int64_t deltaA = 0, deltaB = 0;
            if (arr1[d] + ord > a) {
                deltaA = a - arr1[d];
            } else {
                deltaA = ord;
            }
            if (arr2[d] + ord > b) {
                deltaB = b - arr2[d];
            } else {
                deltaB = ord;
            }
            arr1[d] = arr1[d] + deltaA;
            arr2[d] = arr2[d] + deltaB;
            Fta.update(d, deltaA);
            Ftb.update(d, deltaB);
        } else {
            int p;
            cin >> p;
            int64_t ans = Ftb.sum(1, p - 1) + Fta.sum(p + k, n);
            cout << ans << '\n';
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
