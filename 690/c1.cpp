#include <bits/stdc++.h>
using namespace std;

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
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    if (m != n - 1) {
        cout << "no\n";
        return;
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.join(u, v);
    }
    set<int> p;
    for (int i = 0; i < n; i++) {
        p.insert(dsu.find(i));
    }
    cout << ((int)p.size() == 1 ? "yes\n" : "no\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
