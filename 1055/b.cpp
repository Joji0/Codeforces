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

struct DSU {
    vector<int64_t> parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (a < b)
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    // The idea is to utilize the DSU data structure. The problem can be reduced
    // to the more obvious problem: Think of the hairlines as weight of
    // a graph and each adjacent hairlines (i and i + 1 for 1 <= i < n) are
    // connected if and only if their weight > l. Our task is then for each
    // query of type 0 we can simply seek out the number of connected
    // components. For query of type 1, we can increase the weight of such
    // vertex and if its weight exceeds l we can connect with the neighbors of
    // this particular hairline.
    int n, m, l, cnt = 0;
    // cnt = number of connected components for weight > l
    cin >> n >> m >> l;
    vector<int64_t> hair(n + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> hair[i];
        if (hair[i] > l)
            cnt++;
    }
    for (int i = 1; i < n; i++) {
        if (hair[i] > l && hair[i + 1] > l) {
            dsu.join(i, i + 1);
            cnt--;
        }
    }
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type) {
            int idx, d;
            cin >> idx >> d;
            if (hair[idx] <= l) {
                hair[idx] += d;
                if (hair[idx] > l) {
                    cnt++;
                    if (hair[idx] > l && idx + 1 <= n && hair[idx + 1] > l &&
                        dsu.find(idx) != dsu.find(idx + 1)) {
                        dsu.join(idx, idx + 1);
                        cnt--;
                    }
                    if (hair[idx] > l && idx - 1 >= 1 && hair[idx - 1] > l &&
                        dsu.find(idx) != dsu.find(idx - 1)) {
                        dsu.join(idx, idx - 1);
                        cnt--;
                    }
                }
            }
        } else {
            cout << cnt << '\n';
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
