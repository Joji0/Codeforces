#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
int dp[300005];
vector<int> child[300005];
map<int, ll> mp;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    mp[1] = 0;
    while (!q.empty()) {
        auto [node, height] = q.front();
        q.pop();
        for (auto &u : child[node]) {
            if (node == 1) {
                dp[u] = 1;
                mp[2]++;
            } else {
                dp[u] += (mp[height] - dp[node]) % MOD;
                mp[height + 1] += dp[u] % MOD;
            }
            q.push({u, height + 1});
        }
    }
}

void solve() {
    int n;
    cin >> n;
    mp.clear();
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        child[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        child[par].push_back(i);
    }
    bfs();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i] % MOD;
        ans %= MOD;
    }
    cout << (ans + 1) % MOD << '\n';
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
