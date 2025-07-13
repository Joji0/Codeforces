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
    int n, t, m, idx = 0;
    cin >> n >> t;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    cin >> m;
    queue<pair<string, int>> cards;
    vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
    map<string, int> id;
    map<int, vector<string>> won;
    vector<int> score(n, 0);
    for (int i = 0; i < m; i++) {
        string s;
        int c;
        cin >> s >> c;
        cards.push({s, c});
        id[s] = idx++;
    }
    int i = 0;
    bool first = true;
    while (!cards.empty()) {
        int init = t;
        while (init > 0 && !cards.empty()) {
            auto [s, complexity] = cards.front();
            cards.pop();
            int need = max(1, complexity -
                                  (first ? (a[i].first + b[i].second)
                                         : (a[i].second + b[i].first)) -
                                  d[i][id[s]]);
            if (init >= need) {
                won[i].push_back(s);
                score[i]++;
                init -= need;
            } else {
                d[i][id[s]] += init;
                cards.push({s, complexity});
                break;
            }
        }
        if (i + 1 == n) {
            i = 0;
            if (first) {
                first = false;
            } else {
                first = true;
            }
        } else {
            i++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << score[i] << " ";
        for (auto &x : won[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
