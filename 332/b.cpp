#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> X(n), S(n);
    for (auto &x : X)
        cin >> x;
    int64_t sum = 0;
    for (int i = 0; i < k; i++) {
        sum += X[i];
    }
    S[0] = sum;
    for (int i = 1; i <= n - k; i++) {
        sum = sum - X[i - 1] + X[i + k - 1];
        S[i] = sum;
    }
    vector<int> suff(n - k + 1);
    suff[n - k] = n - k;
    for (int i = n - k - 1; i >= 0; i--) {
        if (S[i] >= S[suff[i + 1]]) {
            suff[i] = i;
        } else {
            suff[i] = suff[i + 1];
        }
    }
    int64_t best = -1;
    int a = -1, b = -1;
    for (int i = 0; i + k <= n - k; i++) {
        int tr = suff[i + k];
        int64_t x = S[i] + S[tr];
        if (x > best) {
            best = x;
            a = i;
            b = tr;
        }
    }
    cout << a + 1 << " " << b + 1 << '\n';
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
