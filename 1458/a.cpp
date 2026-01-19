#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N), B(M);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    vector<int64_t> ans(M);
    if (N > 1) {
        int64_t G = abs(A[1] - A[0]);
        for (int i = 1; i < N; i++) {
            G = gcd(G, abs(A[i] - A[0]));
        }
        for (int i = 0; i < M; i++) {
            ans[i] = gcd(G, A[0] + B[i]);
        }
    } else {
        for (int i = 0; i < M; i++) {
            ans[i] = A[0] + B[i];
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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
