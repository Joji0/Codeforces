#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, m, step = 0;
    string x, s;
    cin >> n >> m >> x >> s;
    while ((int)x.size() < 1000) {
        if (x.find(s) != string::npos) {
            cout << step << '\n';
            return;
        }
        x = x + x;
        step++;
    }
    cout << "-1\n";
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
