#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    int64_t init = 0, ans = INF;
    for (int i = 0; i < N - 1; i++) {
        init += abs(A[i + 1] - A[i]);
    }
    for (int i = 0; i < N; i++) {
        int64_t now = INF;
        if (i > 0 && i < N - 1) {
            now = init - abs(A[i + 1] - A[i]) - abs(A[i] - A[i - 1]) +
                  abs(A[i + 1] - A[i - 1]);
        } else if (i != N - 1) {
            now = init - abs(A[i + 1] - A[i]);
        } else {
            now = init - abs(A[i] - A[i - 1]);
        }
        ans = min(ans, now);
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
