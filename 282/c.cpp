#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    if ((int)a.size() != (int)b.size()) {
        cout << "NO\n";
        return;
    }
    bool ok1 = a.find('1') != string::npos, ok2 = b.find('1') != string::npos;
    cout << (ok1 == ok2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
