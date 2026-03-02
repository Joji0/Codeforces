#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        vector<array<int, 2>> A(N);
        for (int i = 0; i < N; i++) {
                cin >> A[i][0] >> A[i][1];
        }
        sort(A.begin(), A.end());
        int ans = 0;
        int last_left = A[0][0], last_right = A[0][1];
        for (int i = 1; i < N; i++) {
                auto covered = [&](const array<int, 2> P) -> bool { return last_left < P[0] && P[1] < last_right; };
                if (!covered(A[i])) {
                        last_left = A[i][0], last_right = A[i][1];
                } else {
                        ans++;
                }
        }
        cout << ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
