#include <bits/stdc++.h>
using namespace std;

void solve() {
        int64_t p, q;
        cin >> p >> q;
        int64_t g = gcd(p, q);
        p /= g;
        q /= g;
        int N;
        cin >> N;
        vector<int64_t> A(N);
        for (auto &x : A) cin >> x;
        if (N == 1) {
                if (p % q) {
                        cout << "NO\n";
                        return;
                }
                p /= q;
                if (p == A[0]) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
                return;
        }
        reverse(A.begin(), A.end());
        int64_t den = A[0], num = A[1];
        for (int i = 2; i < N; i++) {
                num = num * den + 1;
                if (num % den == 0) {
                        num /= den;
                        den = 1;
                }
                den = num, num = A[i];
        }
        num = num * den + 1;
        g = gcd(num, den);
        num /= g, den /= g;
        if (p == num && q == den) {
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
        while (t--) solve();

        return 0;
}
