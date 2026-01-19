#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), sorted;
    for (auto &x : A)
        cin >> x;
    sorted = A;
    sort(sorted.begin(), sorted.end());
    if (A == sorted) {
        cout << "YES\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != sorted[i]) {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
