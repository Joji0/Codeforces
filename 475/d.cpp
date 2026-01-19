#include <bits/stdc++.h>
using namespace std;

const int LOG = 25;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    vector<vector<int64_t>> sparseTable(LOG, vector<int64_t>(N));
    for (int j = 0; j < N; j++) {
        sparseTable[0][j] = A[j];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j + (1LL << i) - 1 < N; j++) {
            sparseTable[i][j] = gcd(sparseTable[i - 1][j],
                                    sparseTable[i - 1][j + (1LL << (i - 1))]);
        }
    }
    auto query = [&](const int &L, const int &R) -> int64_t {
        int len = R - L + 1;
        int lg = (int)log2(len);
        return gcd(sparseTable[lg][L], sparseTable[lg][R - (1LL << lg) + 1]);
    };
    map<int64_t, int64_t> ans;
    for (int l = 0; l < N; l++) {
        int r = l;
        while (r < N) {
            int64_t g = query(l, r);
            int lf = r, rg = N - 1, best = r;
            while (lf <= rg) {
                int mid = (lf + rg) / 2;
                if (query(l, mid) == g) {
                    best = mid;
                    lf = mid + 1;
                } else {
                    rg = mid - 1;
                }
            }
            ans[g] += best - r + 1;
            r = best + 1;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t x;
        cin >> x;
        cout << ans[x] << '\n';
    }
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
