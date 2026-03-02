#include "ds/hashmap.hpp"
#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
        int N, Q;
        cin >> N >> Q;
        vector<int64_t> C(N), V(N);
        for (auto &v : V) cin >> v;
        for (auto &c : C) cin >> c;
        HashMap<int64_t, int64_t> dp;
        while (Q--) {
                dp.build(1 << 17);
                int64_t a, b;
                cin >> a >> b;
                int64_t best1 = -INF, best2 = -INF, best1_color = -1;
                for (int i = 0; i < N; i++) {
                        int64_t prev_same = dp.get(C[i], -INF), prev = -INF;
                        if (prev_same != -INF) {
                                prev = prev_same + V[i] * a;
                        }
                        int64_t diff = -INF;
                        if (C[i] != best1_color) {
                                diff = max(diff, best1 + V[i] * b);
                        } else {
                                diff = max(diff, best2 + V[i] * b);
                        }
                        int64_t now = max({prev, diff, V[i] * b});
                        if (now > best1) {
                                if (best1_color == C[i]) {
                                        best1 = now;
                                } else {
                                        best2 = best1;
                                        best1_color = C[i];
                                        best1 = now;
                                }
                        } else if (now > best2 && C[i] != best1_color) {
                                best2 = now;
                        }
                        if (now > prev_same) {
                                dp[C[i]] = now;
                        }
                }
                cout << max(0LL, best1) << '\n';
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
