#include <bits/stdc++.h>
using namespace std;

void solve() {
        int pick = -1, N, pos = -1, at = -1;
        cin >> N;
        vector<int> perm(N), best(N);
        iota(best.begin(), best.end(), 1);
        reverse(best.begin(), best.end());
        for (auto &x : perm) cin >> x;
        for (int i = 0; i < N; i++) {
                if (perm[i] != best[i]) {
                        pick = best[i];
                        at = i;
                        break;
                }
        }
        for (int i = 0; i < N; i++) {
                if (perm[i] == pick) {
                        pos = i;
                }
        }
        if (pick == -1) {
                for (auto &x : perm) {
                        cout << x << " ";
                }
                cout << '\n';
                return;
        } else {
                assert(at <= pos);
                reverse(perm.begin() + at, perm.begin() + pos + 1);
                for (auto &x : perm) {
                        cout << x << " ";
                }
                cout << '\n';
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
