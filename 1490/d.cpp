#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ans[105];
int dfs[105];

void DC(vector<int> a, int depth) {
    if (a.empty())
        return;
    auto f = max_element(a.begin(), a.end());
    ans[dfs[*f]] = depth;
    vector<int> l(a.begin(), f);
    vector<int> r(f + 1, a.end());
    DC(l, depth + 1);
    DC(r, depth + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dfs[a[i]] = i + 1;
    }
    memset(ans, 0, sizeof(ans));
    DC(a, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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
