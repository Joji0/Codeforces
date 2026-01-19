#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 2, r = 999, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << "? 1 " << mid << endl;
        int resp;
        cin >> resp;
        if (resp != mid) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    assert(ans != -1);
    cout << "! " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
