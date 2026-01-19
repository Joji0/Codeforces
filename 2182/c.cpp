#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    for (auto &x : C)
        cin >> x;
    int64_t cnt1 = 0, cnt2 = 0;
    for (int shift = 0; shift < N; shift++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (A[i] >= B[(i + shift) % N]) {
                ok = false;
                break;
            }
        }
        cnt1 += ok;
    }
    for (int shift = 0; shift < N; shift++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (B[i] >= C[(i + shift) % N]) {
                ok = false;
                break;
            }
        }
        cnt2 += ok;
    }
    int64_t ans = N * cnt1 * cnt2;
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
