#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N), B(N), pref(N + 1);
        for (auto &x : A) cin >> x;
        for (auto &x : B) cin >> x;
        for (int i = 0; i < N; i++) {
                A[i] = max(A[i], B[i]);
        }
        for (int i = N - 2; i >= 0; i--) {
                A[i] = max(A[i], A[i + 1]);
        }
        for (int i = 1; i <= N; i++) {
                pref[i] = pref[i - 1] + A[i - 1];
        }
        while (Q--) {
                int L, R;
                cin >> L >> R;
                cout << pref[R] - pref[L - 1] << " ";
        }
        cout << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
