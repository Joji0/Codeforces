#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    auto ok = [&](int a, int b, int c) -> bool {
        a %= 3, b %= 3, c %= 3;
        bool ok1 = (a != b && b != c && a != c);
        bool ok2 = (a == b && b == c);
        return ok1 || ok2;
    };
    int sum = accumulate(A.begin(), A.end(), 0);
    for (int l = 0; l < n - 2; l++) {
        for (int r = l + 1; r < n - 1; r++) {
            int s1 = 0, s2 = 0;
            for (int i = 0; i <= l; i++) {
                s1 += A[i];
            }
            for (int i = l + 1; i <= r; i++) {
                s2 += A[i];
            }
            int s3 = sum - (s1 + s2);
            if (ok(s1, s2, s3)) {
                // cerr << "DEBUG\n";
                // cerr << s1 << " " << s2 << " " << s3 << '\n';
                cout << l + 1 << " " << r + 1 << '\n';
                return;
            }
        }
    }
    cout << "0 0\n";
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
