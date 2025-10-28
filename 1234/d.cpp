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
#ifndef ONLINE_JUDGE
#define IOJUDGE(title)                                                         \
    freopen(title ".in", "r", stdin), freopen(title ".out", "w", stdout)
#else
#define IOJUDGE(title)
#endif
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

struct Node {
    int mask = 0;
};

Node merge(Node a, Node b) {
    Node ret;
    ret.mask = a.mask | b.mask;
    return ret;
}

struct SegmentTree {
    vt<Node> t;
    int n;

    SegmentTree(int n) {
        this->n = n;
        Node base;
        t.assign(4 * n, base);
    }

    void build(const string &a, int v, int tl, int tr) {
        if (tl == tr) {
            Node curr;
            curr.mask |= (1 << (a[tl] - 'a'));
            t[v] = curr;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    void build(const string &a) { build(a, 1, 0, n - 1); }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return {};
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int v, int tl, int tr, int pos, char old_char, char new_char) {
        if (tl == tr) {
            t[v].mask = t[v].mask & (~(1LL << (old_char - 'a')));
            t[v].mask = t[v].mask | (1LL << (new_char - 'a'));
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, old_char, new_char);
            else
                update(v * 2 + 1, tm + 1, tr, pos, old_char, new_char);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    void update(int pos, char old_char, char new_char) {
        update(1, 0, n - 1, pos, old_char, new_char);
    }
};

void solve() {
    string s;
    int Q;
    cin >> s >> Q;
    SegmentTree segT(sz(s));
    segT.build(s);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            segT.update(pos - 1, s[pos - 1], c);
            s[pos - 1] = c;
        } else {
            int l, r;
            cin >> l >> r;
            Node ans = segT.query(l - 1, r - 1);
            cout << popcnt32(ans.mask) << '\n';
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
