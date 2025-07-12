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
    int n, m, k, nleft, mleft, ones = 0, zeros = 0, record = 0;
    cin >> n >> m >> k;
    char ch;
    int maxx = max(n, m);
    nleft = n, mleft = m;
    if (n > m) {
        ch = '0';
        nleft -= k;
        zeros += k;
    } else {
        ch = '1';
        mleft -= k;
        ones += k;
    }
    if (maxx < k) {
        cout << "-1\n";
        return;
    }
    record = k;
    string s(k, ch);
    for (int i = k; i < n + m; i++) {
        bool can = true;
        if ((ch == '0' && (k % 2)) || (ch == '1' && (k % 2) == 0)) {
            if (i % 2) {
                if (mleft) {
                    s += '1';
                    ones++;
                } else {
                    can = false;
                    s += string(n + m - i, '0');
                    zeros += n + m - i;
                }
                mleft--;
            } else {
                if (nleft) {
                    s += '0';
                    zeros++;
                } else {
                    can = false;
                    s += string(n + m - i, '1');
                    ones += n + m - i;
                }
                nleft--;
            }
        } else {
            if (i % 2) {
                if (nleft) {
                    s += '0';
                    zeros++;
                } else {
                    can = false;
                    s += string(n + m - i, '1');
                    ones += n + m - i;
                }
                nleft--;
            } else {
                if (mleft) {
                    s += '1';
                    ones++;
                } else {
                    can = false;
                    s += string(n + m - i, '0');
                    zeros += n + m - i;
                }
                mleft--;
            }
        }
        chmax(record, abs(zeros - ones));
        if (!can) {
            break;
        }
    }
    // debug(s);
    if (record > k || (int)s.size() != n + m) {
        cout << "-1\n";
        return;
    }
    cout << s << '\n';
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
