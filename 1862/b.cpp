#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n), a;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    a.push_back(b.front());
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i - 1])
            a.push_back(1);
        a.push_back(b[i]);
    }
    cout << a.size() << '\n';
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << '\n';
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
