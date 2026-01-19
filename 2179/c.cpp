#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    sort(A.begin(), A.end());
    cout << max(A[0], A[1] - A[0]) << '\n';
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
