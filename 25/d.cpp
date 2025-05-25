#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
    int join(int a, int b) {
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
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        dsu.join(a, b);
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
