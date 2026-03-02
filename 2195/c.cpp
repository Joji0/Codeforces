#include <bits/stdc++.h>
using namespace std;
int n, a[1 << 20];
void solve() {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int cnt = 0;
        for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1] || a[i] + a[i - 1] == 7) {
                        if (i + 1 < n) {
                                int wt = -1;
                                for (int j = 1; j <= 6; j++) {
                                        if (a[i + 1] != j && a[i + 1] + j != 7 && a[i - 1] != j && a[i - 1] + j != 7) {
                                                wt = j;
                                                break;
                                        }
                                }
                                if (wt == -1)
                                        a[i] = 7 - a[i + 1];
                                else
                                        a[i] = wt;
                        }
                        cnt++;
                }
        }
        cout << cnt << '\n';
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int tc = 1;
        cin >> tc;
        while (tc--) solve();
        return 0;
}
