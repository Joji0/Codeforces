#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
        bool ok = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if (x == 67) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        cin >> tc;
        while (tc--) solve();
        return 0;
}
