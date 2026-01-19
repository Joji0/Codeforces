#include <bits/stdc++.h>
using namespace std;

const int LOG = 25;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    int Q;
    cin >> Q;
    vector<vector<int64_t>> sparseTable(LOG, vector<int64_t>(N, 0));
    for (int j = 0; j < N; j++) {
        sparseTable[0][j] = A[j];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j + (1LL << i) - 1 < N; j++) {
            sparseTable[i][j] = (sparseTable[i - 1][j] &
                                 sparseTable[i - 1][j + (1LL << (i - 1))]);
        }
    }
    auto query = [&](const int &L, const int &R) -> int64_t {
        int len = R - L + 1;
        int lg = (int)log2(len);
        return sparseTable[lg][L] & sparseTable[lg][R - (1LL << lg) + 1];
    };
    auto ok = [&](const int &mid, const int &L, const int64_t &K) -> bool {
        return query(L, mid) >= K;
    };
    while (Q--) {
        int L, K;
        cin >> L >> K;
        int l = L - 1, r = N - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid, L - 1, K)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << (ans == -1 ? -1 : ans + 1) << " ";
    }
    cout << '\n';
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
