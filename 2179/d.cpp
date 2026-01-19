#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < (1 << N); i++) {
        st.insert(i);
    }
    vector<int> ans;
    ans.push_back((1 << N) - 1);
    for (int i = 0; i < N; i++) {
        int val = (1 << i) - 1;
        ans.push_back(val);
        st.erase(val);
    }
    for (int x : st) {
        ans.push_back(x);
    }
    for (auto &x : ans) {
        cout << x << " ";
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
