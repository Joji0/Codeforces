#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, y, r;
    cin >> n >> y >> r;
    cout << min(n, y / 2 + r) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
