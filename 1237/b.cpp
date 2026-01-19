#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    set<int> done;
    int ans = 0, ptr = 0;
    for (int i = 0; i < n;) {
        int expect = A[ptr];
        if (done.contains(A[ptr])) {
            ptr++;
            continue;
        } else {
            if (expect != B[i])
                ans++;
            else
                ptr++;
            done.insert(B[i]);
            i++;
        }
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
