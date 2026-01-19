#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    auto f = [&]() -> vector<int> {
        vector<int> ret;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                ret.push_back(i);
                if (N % (N / i) == 0 && i != N / i) {
                    ret.push_back(N / i);
                }
            }
        }
        return ret;
    };
    vector<int> divs = f(), dp(N, 0);
    for (auto &x : divs) {
        if (N / x < 3)
            continue;
        dp.assign(N, 0);
        for (int i = 0; i < N; i++) {
            dp[i] = (dp[(i - x + N) % N] + A[i]);
            if (!A[i])
                dp[i] = 0;
            if (dp[i] == N / x) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
