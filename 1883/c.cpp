#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int x, int k) {
    int cnt = 0;
    while (x % k) {
        x++;
        cnt++;
    }
    return cnt;
}

int g(vector<int> &a) {
    int idxmin = 0, minn1 = 10, minn2 = 10;
    for (int i = 0; i < (int)a.size(); i++) {
        if (f(a[i], 2) < minn1) {
            minn1 = f(a[i], 2);
            idxmin = i;
        }
    }
    for (int i = 0; i < (int)a.size(); i++) {
        if (f(a[i], 2) < minn2 && i != idxmin) {
            minn2 = f(a[i], 2);
        }
    }
    return (minn1 + minn2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 10;
    for (auto &x : a) {
        cin >> x;
        ans = min(ans, f(x, k));
    }
    if (k == 4) {
        ans = min(ans, g(a));
    }
    cout << ans << '\n';
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
