#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, s = 0, p = 1, steps = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        s += x;
        p *= x;
    }
    if (s >= 0 && p == 1) {
        cout << "0\n";
        return;
    } else if (s < 0) {
        while (s < 0) {
            s += 2;
            p *= -1;
            steps++;
        }
        if (p != 1)
            steps++;
        cout << steps << '\n';
    } else {
        cout << "1\n";
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
