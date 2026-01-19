#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<array<int64_t, 2>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i][1];
    }
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        mp[abs(A[i][1])] += A[i][0];
    }
    int64_t have = 0;
    for (auto &[dist, h] : mp) {
        have += h;
        if (have > dist * K) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
