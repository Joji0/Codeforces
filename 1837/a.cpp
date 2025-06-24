#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int x, k, steps = 1;
    cin >> x >> k;
    int get = x;
    while (get % k == 0) {
        get--;
        steps++;
    }
    cout << steps << "\n";
    if (steps > 1)
        cout << get << " " << x - get << '\n';
    else
        cout << get << '\n';
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
