#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<int64_t> mx;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
        mx.assign(n, 0LL);
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
            mx[a] += mx[b];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n), perm(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : perm) {
        cin >> x;
        x--;
    }
    reverse(perm.begin(), perm.end());
    vector<int64_t> ans(n);
    vector<bool> on(n, false);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        dsu.mx[i] = A[i];
    }
    int64_t hold = 0;
    for (int i = 1; i < n; i++) {
        auto now = perm[i - 1];
        hold = max(hold, A[now]);
        if (now - 1 >= 0 && on[now - 1]) {
            dsu.join(now - 1, now);
            hold = max(hold, dsu.mx[dsu.find(now)]);
        }
        if (now + 1 < n && on[now + 1]) {
            dsu.join(now, now + 1);
            hold = max(hold, dsu.mx[dsu.find(now)]);
        }
        on[now] = true;
        ans[i] = hold;
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x << '\n';
    }
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
