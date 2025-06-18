#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    bool ok = true, can = true;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a) {
            ok = false;
        }
        if (!ok) {
            if (x)
                x--;
            else if (a) {
                can = false;
            }
        }
    }
    cout << (can ? "YES\n" : "NO\n");
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
