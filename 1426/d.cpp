#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    set<int64_t> st;
    st.insert(0);
    int64_t pref = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        pref += A[i];
        if (st.contains(pref)) {
            st.clear();
            ans++;
            st.insert(0);
            pref = A[i];
        }
        st.insert(pref);
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
