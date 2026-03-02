#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        vector<int64_t> A(N), B(N), pref(N);
        int64_t suff = 0;
        for (auto &x : A) cin >> x;
        for (auto &x : B) cin >> x;
        pref[0] = B[0];
        for (int i = 1; i < N; i++) {
                pref[i] = pref[i - 1] + B[i];
        }
        sort(A.rbegin(), A.rend());
        map<int64_t, int64_t> mp;
        for (int i = 0; i < N; i++) {
                mp[A[i]] = suff + A[i];
                suff += A[i];
        }
        for (auto &[a, b] : mp) {
                cerr << "A: " << a << " B: " << b << '\n';
        }
        int64_t ans = 0;
        for (auto &x : A) {
                auto it = lower_bound(pref.begin(), pref.end(), mp[x]) - pref.begin() + 1;
                ans = max(ans, it * x);
        }
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
