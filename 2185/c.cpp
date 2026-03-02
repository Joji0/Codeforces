#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        vector<int64_t> A(N);
        for (auto &x : A) cin >> x;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int consec = 0, ans = 0;
        for (int i = 0; i < N; i++) {
                if (i == 0) {
                        consec++;
                } else {
                        if (A[i] == A[i - 1] + 1) {
                                consec++;
                        } else {
                                ans = max(ans, consec);
                                consec = 1;
                        }
                }
        }
        ans = max(ans, consec);
        cout << ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
