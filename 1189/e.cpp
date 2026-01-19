#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, P, K;
    cin >> N >> P >> K;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    int64_t ans = 0;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        int64_t now = ((A[i] % P) * (A[i] % P)) % P;
        now *= now % P;
        now %= P;
        now -= (K * A[i]) % P;
        now += P;
        now %= P;
        ans += mp[now];
        mp[now]++;
    }
    cout << ans << '\n';
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
