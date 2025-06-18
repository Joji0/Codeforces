#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, s = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        s += val;
    }
    cout << -s << '\n';
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
