#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    set<int> st;
    priority_queue<int> pq;
    for (auto &x : p)
        st.insert(x);
    for (int i = 1; i <= n; i++) {
        if (!st.contains(i)) {
            pq.push(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            p[i] = pq.top();
            pq.pop();
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] != i + 1) {
            r = i;
            break;
        }
    }
    cout << r - l + (r != l) << '\n';
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
