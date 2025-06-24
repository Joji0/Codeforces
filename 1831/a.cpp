#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        cout << n - a[i] + 1 << " \n"[i == n - 1];
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
