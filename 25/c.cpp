#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int adj[305][305], n, k;
// HEBAT OVERFLOW
vector<ll> ans;

void floydwarshall(int u, int v, int w, int idx) {
    ll sum = 0;
    adj[u][v] = min(adj[u][v], w);
    adj[v][u] = adj[u][v];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = min(adj[i][j], adj[i][u] + w + adj[v][j]);
            adj[i][j] = min(adj[i][j], adj[i][v] + w + adj[u][j]);
            sum += adj[i][j];
        }
    }
    ans[idx] = sum / 2;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    cin >> k;
    ans.resize(k);
    for (int i = 0; i < k; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        floydwarshall(a, b, w, i);
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
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
