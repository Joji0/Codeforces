#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b, c;
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == a.front()) {
            b.push_back(a[i]);
        } else {
            break;
        }
    }
    for (; i < n; i++) {
        c.push_back(a[i]);
    }
    if (b.empty() || c.empty()) {
        cout << "-1\n";
        return;
    }
    cout << b.size() << " " << c.size() << '\n';
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " \n"[i == b.size() - 1];
    }
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " \n"[i == c.size() - 1];
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
