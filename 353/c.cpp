#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    string s;
    cin >> s;
    vector<int64_t> pref(N);
    for (int i = 0; i < N; i++) {
        pref[i] = (i ? pref[i - 1] : 0) + A[i];
    }
    vector<int> on;
    int64_t init = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            on.push_back(i);
            init += A[i];
        }
    }
    int64_t ans = init;
    for (auto &i : on) {
        ans = max(ans, init - A[i] + (i ? pref[i - 1] : 0));
        init -= A[i];
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
