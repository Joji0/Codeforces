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

struct Properties {
    int points = 0, diff = 0, scored = 0;
};

void solve() {
    int n;
    cin >> n;
    map<string, int> id;
    map<int, string> player;
    vt<Properties> V(n);
    vt<int> ans(n);
    iota(all(ans), 0);
    int idx = 0;
    FOR(n) {
        string s;
        cin >> s;
        id[s] = idx;
        player[idx] = s;
        idx++;
    }
    FOR(n * (n - 1) / 2) {
        string players, score;
        cin >> players >> score;
        string pl1, pl2, sc1, sc2;
        bool next = false;
        FOR(sz(players)) {
            if (players[i] == '-') {
                next = true;
                continue;
            }
            if (!next) {
                pl1 += players[i];
            } else {
                pl2 += players[i];
            }
        }
        next = false;
        FOR(sz(score)) {
            if (score[i] == ':') {
                next = true;
                continue;
            }
            if (!next) {
                sc1 += score[i];
            } else {
                sc2 += score[i];
            }
        }
        int id1 = id[pl1], id2 = id[pl2], score1 = stoi(sc1),
            score2 = stoi(sc2), pts1, pts2;
        if (score1 > score2) {
            pts1 = 3, pts2 = 0;
        } else if (score1 == score2) {
            pts1 = 1, pts2 = 1;
        } else {
            pts1 = 0, pts2 = 3;
        }
        V[id1].points += pts1, V[id2].points += pts2;
        V[id1].diff += score1 - score2;
        V[id2].diff += score2 - score1;
        V[id1].scored += score1;
        V[id2].scored += score2;
    }
    sort(all(ans), [&](int i, int j) {
        if (V[i].points != V[j].points) {
            return V[i].points > V[j].points;
        }
        if (V[i].diff != V[j].diff) {
            return V[i].diff > V[j].diff;
        }
        return V[i].scored > V[j].scored;
    });
    vt<string> out;
    FOR(n / 2) { out.pb(player[ans[i]]); }
    sort(all(out));
    EACH(x, out) { cout << x << '\n'; }
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
