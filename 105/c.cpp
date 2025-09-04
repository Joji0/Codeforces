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

pair<string, array<int, 2>>
searchBest(const vt<pair<string, array<int, 2>>> &base,
           const vt<pair<string, int>> &best, vt<bool> &used,
           const vt<pair<string, array<int, 2>>> &ALL) {
    int mx = -1, idx = -1;
    FOR(sz(base)) {
        int cur = base[i].second[0];
        FOR(j, min(sz(best), base[i].second[1])) { cur += best[j].second; }
        if (chmax(mx, cur)) {
            idx = i;
        }
    }
    FOR(min(sz(best), base[idx].second[1])) {
        FOR(j, sz(ALL)) {
            if (ALL[j].first == best[i].first) {
                used[j] = true;
            }
        }
    }
    return base[idx];
}

void printBest(const pair<string, array<int, 2>> &obj, const vt<string> &res) {
    cout << obj.first << " " << sz(res) << " ";
    EACH(resident, res) { cout << resident << " "; }
    cout << '\n';
}

pair<string, array<int, 2>>
searchLocked(const vt<pair<string, array<int, 2>>> &base,
             map<string, pair<vt<string>, int>> &mp) {
    int mx = -1, pick = -1;
    FOR(sz(base)) {
        if (chmax(mx, base[i].second[0] + mp[base[i].first].second)) {
            pick = i;
        }
    }
    return base[pick];
}

void printLocked(const pair<string, array<int, 2>> &obj,
                 map<string, pair<vt<string>, int>> &mp) {
    cout << obj.first << " " << obj.second[1] << " ";
    EACH(item, mp[obj.first].first) { cout << item << " "; }
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;
    set<string> Wcan, Acan, Ocan;
    vt<pair<string, array<int, 2>>> baseW, baseA, baseO, ALL;
    vt<bool> usedAll;
    map<string, pair<vt<string>, int>> lockedBonus;
    map<string, int> transfer;
    FOR(n) {
        string name, type;
        int atk, def, res, size;
        cin >> name >> type >> atk >> def >> res >> size;
        if (type == "weapon") {
            baseW.pb({name, {atk, size}});
            Wcan.insert(name);
        } else if (type == "armor") {
            baseA.pb({name, {def, size}});
            Acan.insert(name);
        } else {
            baseO.pb({name, {res, size}});
            Ocan.insert(name);
        }
        transfer[name] = size;
    }
    int k;
    cin >> k;
    vt<pair<string, int>> bestW, bestA, bestO;
    FOR(k) {
        string name, type, home;
        int bonus;
        cin >> name >> type >> bonus >> home;
        transfer[home]--;
        ALL.pb({name, {-1, -1}});
        lockedBonus[home].first.pb(name);
        if (type == "gladiator") {
            bestW.pb({name, bonus});
            if (Wcan.contains(home)) {
                lockedBonus[home].second += bonus;
            }
        } else if (type == "sentry") {
            bestA.pb({name, bonus});
            if (Acan.contains(home)) {
                lockedBonus[home].second += bonus;
            }
        } else {
            bestO.pb({name, bonus});
            if (Ocan.contains(home)) {
                lockedBonus[home].second += bonus;
            }
        }
    }
    sort(all(bestW),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    sort(all(bestA),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    sort(all(bestO),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    bool canTransfer = false;
    for (auto &[name, left] : transfer) {
        if (left > 0) {
            canTransfer = true;
        }
    }
    pair<string, array<int, 2>> weapon, armor, orb;
    usedAll.assign(sz(ALL), false);
    if (canTransfer) {
        weapon = searchBest(baseW, bestW, usedAll, ALL);
        armor = searchBest(baseA, bestA, usedAll, ALL);
        orb = searchBest(baseO, bestO, usedAll, ALL);
        int leftW = max(0, weapon.second[1] - sz(bestW)),
            leftA = max(0, armor.second[1] - sz(bestA)),
            leftO = max(0, orb.second[1] - sz(bestO));
        vt<string> WRes, ARes, ORes;
        FOR(min(sz(bestW), weapon.second[1])) { WRes.pb(bestW[i].first); }
        FOR(min(sz(bestA), armor.second[1])) { ARes.pb(bestA[i].first); }
        FOR(min(sz(bestO), orb.second[1])) { ORes.pb(bestO[i].first); }
        if (leftW > 0) {
            FOR(sz(usedAll)) {
                if (!usedAll[i]) {
                    leftW--;
                    WRes.pb(ALL[i].first);
                    usedAll[i] = true;
                }
                if (leftW <= 0)
                    break;
            }
        }
        if (leftA > 0) {
            FOR(sz(usedAll)) {
                if (!usedAll[i]) {
                    leftA--;
                    ARes.pb(ALL[i].first);
                    usedAll[i] = true;
                }
                if (leftA <= 0)
                    break;
            }
        }
        if (leftO > 0) {
            FOR(sz(usedAll)) {
                if (!usedAll[i]) {
                    leftO--;
                    ORes.pb(ALL[i].first);
                    usedAll[i] = true;
                }
                if (leftO <= 0)
                    break;
            }
        }
        printBest(weapon, WRes);
        printBest(armor, ARes);
        printBest(orb, ORes);
    } else {
        weapon = searchLocked(baseW, lockedBonus);
        armor = searchLocked(baseA, lockedBonus);
        orb = searchLocked(baseO, lockedBonus);
        printLocked(weapon, lockedBonus);
        printLocked(armor, lockedBonus);
        printLocked(orb, lockedBonus);
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
