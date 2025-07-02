#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Env {
    int w, h, order;
    bool operator<(const Env &x) const {
        if (this->w != x.w) {
            return this->w < x.w;
        }
        return this->h < x.h;
    }
};

vector<Env> env;
int dp[5005], parent[5005];

void solve() {
    int n, w0, h0;
    cin >> n >> w0 >> h0;
    for (int i = 1; i <= n; i++) {
        Env e;
        cin >> e.w >> e.h;
        e.order = i;
        if (e.w > w0 && e.h > h0)
            env.push_back(e);
    }
    sort(env.begin(), env.end(),
         [](const Env &a, const Env &b) { return a < b; });
    memset(parent, -1, sizeof(parent));
    int ans = 0, last = -1;

    // LIS dp approach
    for (int i = 0; i < (int)env.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (env[j].w < env[i].w && env[j].h < env[i].h) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > ans) {
            ans = dp[i];
            last = i;
        }
    }
    cout << ans << '\n';
    vector<int> res;
    while (last != -1) {
        res.push_back(env[last].order);
        last = parent[last];
    }
    reverse(res.begin(), res.end());
    for (auto &x : res) {
        cout << x << " ";
    }
    cout << '\n';
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
