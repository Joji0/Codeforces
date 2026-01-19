#include <bits/stdc++.h>
using namespace std;

const int LOG = 25;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    vector<int> virtualA(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        virtualA[i] = A[i % N];
    }
    vector<vector<int>> sparse(LOG, vector<int>(2 * N));
    for (int j = 0; j < 2 * N; j++) {
        sparse[0][j] = virtualA[j];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j + (1 << i) - 1 < 2 * N; j++) {
            sparse[i][j] =
                gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto query = [&](const int &L, const int &R) -> int {
        int len = R - L + 1;
        int lg = (int)log2(len);
        return gcd(sparse[lg][L], sparse[lg][R - (1LL << lg) + 1]);
    };
    int g = A[0];
    for (int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }
    auto ok = [&](const int &i, const int &mid) -> bool {
        return query(i, mid) <= g;
    };
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int l = i, r = N - 1 + i, best = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(i, mid)) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        assert(best != -1);
        ans = max(ans, best - i);
    }
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
