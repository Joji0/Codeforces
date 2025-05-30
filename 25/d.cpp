#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int adj[1005][1005];

struct DSU {
    vector<int> parent, sz;
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
    int n;
    cin >> n;
    DSU dsu(n + 1);
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        dsu.join(a, b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int p = dsu.find(i);
        st.insert(p);
        // cout << p << '\n';
    }
    vector<int> v(st.begin(), st.end());
    // for (auto x : v)
    //     cout << x << " ";
    // cerr << '\n';
    // sort(v.begin(), v.end(),
    //      [&](const int a, const int b) { return (dsu.sz[a] > dsu.sz[b]); });
    vector<tuple<int, int, int, int>> ans;
    for (int i = 0; i < (int)v.size() - 1; i++) {
        int obj = v[i];
        for (int j = 1; j <= n; j++) {
            int p = dsu.parent[j];
            if (p == obj && adj[obj][j]) {
                ans.push_back({obj, j, obj, v[i + 1]});
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &[a, b, c, d] : ans) {
        cout << a << " " << b << " " << c << " " << d << '\n';
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << dsu.parent[i] << " \n"[i == n];
    // }
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
