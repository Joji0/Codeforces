#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> A(n), pref(n + 1);
    for (int i = 0; i <= n; i++) {
        pref[i] = i;
    }
    pref[r] = pref[l - 1];
    for (int i = 1; i <= n; i++) {
        A[i - 1] = pref[i] ^ pref[i - 1];
        if (!A[i - 1])
            A[i - 1] = 1;
    }
    for (auto &x : A) {
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
