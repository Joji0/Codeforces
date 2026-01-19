#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        int val = A[i];
        int start = (i + val - 1) / val;
        int j = val * start - i;
        for (; j < i; j += val) {
            if (A[j] * val == j + i) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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
