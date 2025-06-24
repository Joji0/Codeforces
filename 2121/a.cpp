#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int f = a.front(), b = a.back();
    if (s > b) {
        cout << s - f << '\n';
    } else if (s < f) {
        cout << b - s << '\n';
    } else {
        cout << min(s - f + b - f, b - s + b - f) << '\n';
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
