#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    int64_t ans = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] <= Q) {
            cnt++;
        } else {
            if (cnt >= K)
                ans += (cnt - K + 1) * (cnt - K + 2) / 2;
            cnt = 0;
        }
    }
    if (cnt >= K) {
        ans += (cnt - K + 1) * (cnt - K + 2) / 2;
    }
    cout << ans << '\n';
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
