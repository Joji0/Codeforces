#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int s[6] = {4, 8, 15, 16, 23, 42};

pair<int, int> f(int x) {
    for (auto &u : s) {
        if (x % u == 0 && find(s, s + 6, x / u) != s + 6 && u != x / u) {
            return {u, x / u};
        }
    }
}

void solve() {
    vector<int> a(6, -1);
    int resp;
    for (int i = 1; i <= 5; i += 2) {
        cout << "? " << i << " " << i + 1 << endl;
        cin >> resp;
        pair<int, int> get = f(resp);
        a[i - 1] = get.first;
        a[i] = get.second;
    }
    cout << "! ";
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << endl;
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
