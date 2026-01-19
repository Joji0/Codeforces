#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    if (N > M) {
        cout << "0\n";
        return;
    }
    int64_t ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans *= abs(A[i] - A[j]) % M;
            ans %= M;
        }
    }
    cout << ans << '\n';
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
