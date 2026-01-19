#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t P, D;
    cin >> P >> D;
    int pw = 0;
    int64_t ans = -1;
    if (P <= 9) {
        cout << P << '\n';
        return;
    }
    for (;;) {
        int64_t now = P - P % (int64_t)pow(10, pw) - 1;
        if (P - now > D)
            break;
        pw++;
        ans = now;
    }
    int cnt = 0;
    int64_t N = P;
    for (;;) {
        if (N < 9)
            break;
        int back = N % 10;
        if (back != 9)
            break;
        N /= 10;
        cnt++;
    }
    cout << (ans == -1 || pw == 1 || cnt + 1 >= pw ? P : ans) << '\n';
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
