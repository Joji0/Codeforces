#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    set<int> st;
    for (auto &x : A) {
        cin >> x;
        st.insert(x);
    }
    int sz = st.size();
    for (auto &x : st) {
        if (x >= sz) {
            cout << x << '\n';
            return;
        }
    }
    cout << sz << '\n';
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
