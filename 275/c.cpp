#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    int64_t K;
    cin >> N >> K;
    set<int64_t> st, rem;
    for (int i = 0; i < N; i++) {
        int64_t x;
        cin >> x;
        st.insert(x);
    }
    for (auto &x : st) {
        if (!rem.contains(x) && st.contains(K * x) && x != K * x) {
            rem.insert(K * x);
        }
    }
    int ans = 0;
    for (auto &x : st) {
        if (!rem.contains(x))
            ans++;
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
